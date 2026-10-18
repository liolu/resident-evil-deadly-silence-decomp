"""hunt.py - target choice + attempt memory + automatic trick battery for HAND matching sessions.
Run from a project dir (e.g. projets/heroes-of-mana). State in build/hunt/ (kept between sessions):
  ledger.json  {name: {tries, best, status, profile, notes[], parked, sessions}}   best/NAME.c = best C so far

  hunt.py import [DIR ...]      collect every results.json (+ its .c) of earlier sweeps (default: all Claude scratchpads
                                of this machine + build/hunt/pool): keeps the best C of each unmatched function in best/
  hunt.py next [-n 25] [--max-size B] [--rejudge K] [--all]
                                ranked queue: fewest diffs, small, few earlier tries, never parked; --rejudge K re-judges
                                the top K now (fresh diffs + diff signature: FAMILIES with the same signature are shown
                                together = fix one, regex the rest)
  hunt.py show NAME             ledger notes + best C + compact diff
  hunt.py try NAME [FILE.c] [--rounds 4] [-j 12] [--submit]
                                trick battery, greedy hill climb: every profile (+ -O0..-O4 p/s, 1.2/sp3, -profile),
                                then rounds of single mutations of the best so far (decl order, signedness of each decl
                                and param, volatile param, == / != operand swap, adjacent statement swap, if/else
                                inversion, `default:` last, u8/u16 -> s32 locals); stops at a match. Logs into the ledger,
                                best C -> build/hunt/best/NAME.c. Budget: after 3 `try` runs without a match the function
                                is auto-parked (hidden from `next`; `unpark` brings it back).
  hunt.py sweep [-n 100] [--max-score 40] [--rounds 2] [-j 12]
                                the battery on the head of the queue (never-tried functions), in the background while
                                you hand-fix others; matches -> build/hunt/matched/ (+results.json), then
                                `python tools/workbench.py submit-many build/hunt/matched`. Nothing is submitted by it.
  hunt.py sibs NAME [-n 12] [--min 0.80] [--submit]
                                after a match: unmatched functions whose asm SHAPE is close to NAME (mnemonic sequence
                                similarity); transplants NAME's C (function name, bl targets and pool symbols renamed in
                                order) and judges it on each -> matches, or a ready starting point with N diffs in best/
  hunt.py note NAME "text"      hunt.py park NAME "why" [--re]  (--re: NAME is a regex, parks a whole family)
  hunt.py unpark NAME
"""
import argparse, difflib, glob, gzip, json, os, random, re, sys, time
from multiprocessing import Pool
from pathlib import Path

ROOT = Path.cwd()
HUNT = ROOT / 'build' / 'hunt'
BEST = HUNT / 'best'
LEDGER = HUNT / 'ledger.json'
BUDGET = 3  # `try` runs without a match before a function is auto-parked
RANK = {'match': 0, 'near': 1, 'size': 2, 'compile': 3, 'refused': 4, 'error': 5}
sys.path.insert(0, str(ROOT / 'tools'))


# ------------------------------------------------------------------ ledger
def load():
    try: return json.loads(LEDGER.read_text(encoding='utf-8'))
    except (OSError, ValueError): return {}


def save(led):
    HUNT.mkdir(parents=True, exist_ok=True)
    tmp = LEDGER.with_suffix('.tmp'); tmp.write_text(json.dumps(led, indent=1, sort_keys=True), encoding='utf-8')
    os.replace(tmp, LEDGER)


def update(name, **kw):
    led = load(); e = led.setdefault(name, {'tries': 0, 'notes': []})
    note = kw.pop('note', None)
    if note: e['notes'].append(time.strftime('%m-%d %H:%M ') + note)
    e.update({k: v for k, v in kw.items() if v is not None}); e['last'] = time.strftime('%Y-%m-%d %H:%M')
    save(led); return e


def score(r):
    """lower is better: near diffs, then size gaps, then compile errors."""
    st = r.get('status', 'error')
    if st == 'match': return 0
    if st == 'near': return r.get('diffs', 999)
    if st == 'size': return 300 + 4 * abs(r.get('size', 0) - r.get('target_size', 0)) // 4 + r.get('diffs', 0) // 8
    return 10 ** 6 + RANK.get(st, 9)


def matched_names():
    have = {p.stem for p in (ROOT / 'src' / 'auto').glob('*.c')} | {p.stem for p in (HUNT / 'matched').glob('*.c')}
    try: have |= {x['name'] for x in json.load(open(ROOT / 'build' / 'workbench' / 'pending.json'))}
    except (OSError, ValueError, KeyError, TypeError): pass
    return have


def unmatched_sizes():
    d = json.load(gzip.open(ROOT / 'progress' / 'report.json.gz'))
    return {f['name']: int(f['size']) for u in d['units'] for f in u.get('functions', [])
            if f.get('fuzzy_match_percent', 0) < 100}


# ------------------------------------------------------------------ judging in worker processes
WB = None; CUR = None


def _init(nodiff=False):
    global WB
    import workbench; WB = workbench
    if nodiff:  # objdump of target + candidate = ~2/3 of a judge; the diff TEXT is only needed for display
        WB.pc.disasm = lambda *a, **k: []


def _module(name):
    global CUR, WB
    import importlib
    ov = WB.overlay_index().get(name)
    mod = 'main' if ov is None else name
    if mod != CUR:
        if ov is None:
            if CUR is not None:  # select_module rebinds globals of project/auto_match/probe_compiler: reload them all
                import project, probe_compiler, auto_match
                for m in (project, probe_compiler, auto_match): importlib.reload(m)
                WB = importlib.reload(WB)
        else: WB.select_module(name)
        CUR = mod


def _judge(job):
    name, src, prof = job
    try:
        _module(name)
        r = WB.judge(name, src, prof)
        r['profile'] = r.get('profile') or prof
        return r
    except BaseException as e:  # workbench.function() raises SystemExit for unknown names
        return {'status': 'error', 'match': False, 'errors': str(e)[:300], 'profile': prof}


def _profiles(name):
    _module(name)
    f = WB.function(name)
    if f['mode'] == 'thumb':
        return [f"{v} {e} -thumb".replace('  ', ' ') for v, e in WB.am.COMPILERS]
    base = [f'{v} {e}'.strip() for v, e in WB.am.profiles_for(name, f['size'], f['addr'])]
    more = ['1.2/sp3', '2.0/sp1p5 -profile', '1.2/sp3 -profile']
    more += [f'{v} -O{o},{t}' for v in ('2.0/sp1p5', '1.2/sp3') for o in (0, 1, 2, 3) for t in ('p', 's')] + ['2.0/sp1p5 -O4,s']
    return list(dict.fromkeys(base + more))


# ------------------------------------------------------------------ mutations (text level, on the function NAME only)
DECL = re.compile(r'^(\s+)((?:volatile |const |unsigned |signed )*[A-Za-z_]\w*(?:\s*\*+)?\s+\**\w+(?:\[[^\]]*\])?);\s*(?://.*|/\*.*\*/)?$')
STMT_BAD = re.compile(r'\b(return|break|continue|goto|case|default|if|else|for|while|do|switch)\b|[{}]|^\s*\w+:')
FLIP = {'s32': 'u32', 'u32': 's32', 's16': 'u16', 'u16': 's16', 's8': 'u8', 'u8': 's8', 'int': 'unsigned int',
        'BOOL': 'u32', 'long': 'unsigned long'}


def body_span(src, name):
    m = re.search(rf'^[^\n;]*\b{re.escape(name)}\s*\(([^)]*)\)\s*\{{\s*$', src, re.M)
    if not m: return None
    i, depth = m.end(), 1
    while i < len(src) and depth:
        depth += {'{': 1, '}': -1}.get(src[i], 0); i += 1
    return m.start(), m.end(), i, m  # header start, body start, body end


def mutations(src, name):
    sp = body_span(src, name)
    if not sp: return []
    hs, bs, be, m = sp
    head, body, pre, post = src[hs:bs], src[bs:be], src[:hs], src[be:]
    lines = body.split('\n')
    out = []
    def emit(tag, newlines=None, newhead=None):
        out.append((tag, pre + (newhead or head) + ('\n'.join(newlines) if newlines is not None else body) + post))
    decl = []
    for i, l in enumerate(lines[1:], 1):
        if DECL.match(l) and '(' not in l and '=' not in l: decl.append(i)
        elif l.strip(): break
    # declaration order: every adjacent swap + a few random orders
    for a, b in zip(decl, decl[1:]):
        L = lines[:]; L[a], L[b] = L[b], L[a]; emit(f'decl-swap {a}', L)
    if len(decl) > 2:
        rnd = random.Random(len(src))
        for k in range(min(12, len(decl) * 2)):
            perm = decl[:]; rnd.shuffle(perm); L = lines[:]
            for dst, s in zip(decl, perm): L[dst] = lines[s]
            emit(f'decl-perm {k}', L)
    # signedness of locals and params
    for i in decl:
        for t, u in FLIP.items():
            if re.search(rf'^\s+(?:volatile )?{t}\b', lines[i]):
                L = lines[:]; L[i] = re.sub(rf'\b{t}\b', u, lines[i], count=1); emit(f'flip {t}->{u} l{i}', L); break
        if re.search(r'^\s+(?:u8|s8|u16|s16)\s+\w+;', lines[i]):
            L = lines[:]; L[i] = re.sub(r'\b(u8|s8|u16|s16)\b', 's32', lines[i], count=1); emit(f'widen l{i}', L)
    params = [p.strip() for p in m.group(1).split(',')] if m.group(1).strip() not in ('', 'void') else []
    for k, p in enumerate(params):
        for t, u in FLIP.items():
            if re.match(rf'(?:volatile )?{t}\b', p):
                ps = params[:]; ps[k] = re.sub(rf'\b{t}\b', u, p, count=1)
                emit(f'param-flip {k}', newhead=head.replace(m.group(1), ', '.join(ps), 1)); break
        if not p.startswith('volatile') and p != '...':
            ps = params[:]; ps[k] = 'volatile ' + p
            emit(f'param-volatile {k}', newhead=head.replace(m.group(1), ', '.join(ps), 1))
    # == / != operand swap (simple operands only)
    opnd = r'[\w.\->\[\]]+|\([^()]*\)'
    for mm in re.finditer(rf'({opnd})\s*(==|!=)\s*({opnd})', body):
        nb = body[:mm.start()] + f'{mm.group(3)} {mm.group(2)} {mm.group(1)}' + body[mm.end():]
        out.append((f'cmp-swap @{mm.start()}', pre + head + nb + post))
    # adjacent statement swap (plain statements at the same indentation)
    simple = lambda l: l.strip().endswith(';') and not STMT_BAD.search(l) and not DECL.match(l)  # noqa: E731
    ind = lambda l: len(l) - len(l.lstrip())  # noqa: E731
    for i in range(1, len(lines) - 1):
        if simple(lines[i]) and simple(lines[i + 1]) and ind(lines[i]) == ind(lines[i + 1]):
            L = lines[:]; L[i], L[i + 1] = L[i + 1], L[i]; emit(f'stmt-swap {i}', L)
    # if (c) { A } else { B }  ->  if (!(c)) { B } else { A }   (one-line braces only, the common m2c shape)
    for mm in re.finditer(r'if \((.*)\) \{\n((?:(?!\} else \{).*\n)*?)(\s*)\} else \{\n((?:.*\n)*?)\3\}', body):
        c, a, ws, b = mm.groups()
        if '{' in a or '{' in b: continue
        nb = body[:mm.start()] + f'if (!({c})) {{\n{b}{ws}}} else {{\n{a}{ws}}}' + body[mm.end():]
        out.append((f'if-invert @{mm.start()}', pre + head + nb + post))
    # switch: m2c puts `default:` first, the jump table wants it last
    mm = re.search(r'\n(\s*)default:\n((?:\1    .*\n)+?)(?=\1case )', body)
    if mm:
        blk = mm.group(0); nb = body.replace(blk, '\n', 1)
        k = nb.rfind('\n' + mm.group(1) + '}')
        k2 = nb.rfind('\n', 0, k)
        nb = nb[:k2] + blk.rstrip('\n') + nb[k2:]
        out.append(('default-last', pre + head + nb + post))
    # commutative operand order (`f() + a` vs `a + f()` = add r0,r0,r4 vs add r0,r4,r0)
    term = r'(?:\w+\((?:[^()]|\([^()]*\))*\)|[\w.\->\[\]]+)'
    for mm in re.finditer(rf'(?<![\w)\]])({term}) ([+*&|^]) ({term})(?![\w(\[])', body):
        if mm.group(1) == mm.group(3): continue
        nb = body[:mm.start()] + f'{mm.group(3)} {mm.group(2)} {mm.group(1)}' + body[mm.end():]
        out.append((f'commute @{mm.start()}', pre + head + nb + post))
    # call result through a temp: `return f() + a;` -> `{ s32 t = f(); return t + a; }` (add r0,r0,r4 operand order)
    call = r'\w+\((?:[^()]|\([^()]*\))*\)'
    for mm in re.finditer(rf'^(\s*)(return |\w+ = )(?:({call}) ([+\-*&|^]) ({term})|({term}) ([+\-*&|^]) ({call}));$', body, re.M):
        ws, lead = mm.group(1), mm.group(2)
        c, op, x = (mm.group(3), mm.group(4), mm.group(5)) if mm.group(3) else (mm.group(8), mm.group(7), mm.group(6))
        for order in ((f'hunt_t {op} {x}'), (f'{x} {op} hunt_t')):
            nb = body[:mm.start()] + f'{ws}{{ s32 hunt_t = {c}; {lead}{order}; }}' + body[mm.end():]
            out.append((f'call-temp @{mm.start()}', pre + head + nb + post))
    # pointer + K scaled by the pointee (m2c: `M2C_UNK **p; p + 0x18` means 0x18 BYTES)
    ptrs = set(re.findall(r'\*+\s*(\w+)\s*[;,)]', head + '\n'.join(lines[i] for i in decl)))
    hits = [mm for mm in re.finditer(r'(?<![\w)])(\w+) ([+-]) (0x[0-9A-Fa-f]+|\d+)\b', body) if mm.group(1) in ptrs]
    for mm in hits[:8]:
        nb = body[:mm.start()] + f'((void *)((u8 *){mm.group(1)} {mm.group(2)} {mm.group(3)}))' + body[mm.end():]
        out.append((f'byteptr {mm.group(1)}', pre + head + nb + post))
    if len(hits) > 1:
        nb = re.sub(r'(?<![\w)])(\w+) ([+-]) (0x[0-9A-Fa-f]+|\d+)\b',
                    lambda mm: f'((void *)((u8 *){mm.group(1)} {mm.group(2)} {mm.group(3)}))' if mm.group(1) in ptrs else mm.group(0), body)
        out.append(('byteptr all', pre + head + nb + post))
    # folded constants: `v = 5; if (c) v = 9;` was `v += 4` (addne r2,r2,#4 vs movne r2,#9)
    first = {}
    for i, l in enumerate(lines):
        mm = re.match(r'^(\s*)(\w+) = (-?(?:0x[0-9A-Fa-f]+|\d+));$', l)
        if not mm: continue
        v, k = mm.group(2), int(mm.group(3), 0)
        if v in first and first[v] != k:
            L = lines[:]; dk = k - first[v]
            L[i] = f'{mm.group(1)}{v} {"+" if dk > 0 else "-"}= {abs(dk)};'; emit(f'unfold {v} l{i}', L)
        first.setdefault(v, k)
    out += artifacts(src)
    seen, uniq = {src}, []
    for t, s in out:
        if s not in seen: seen.add(s); uniq.append((t, s))
    return uniq


def balanced(s, i):
    """index just after the ')' that closes the '(' at s[i]."""
    depth = 0
    for j in range(i, len(s)):
        depth += {'(': 1, ')': -1}.get(s[j], 0)
        if depth == 0: return j + 1
    return len(s)


def artifacts(src):
    """m2c idioms that hide plain C (whole-file rewrites, tried in every round)."""
    out = []
    # SECOND_REG(call(..)) = r1 after a call = high half of a 64-bit return value
    if 'SECOND_REG(' in src:
        s, callees = src, set()
        while 'SECOND_REG(' in s:
            i = s.index('SECOND_REG('); j = balanced(s, i + 10)
            inner = s[i + 11:j - 1]; callees |= set(re.findall(r'(\w+)\(', inner))
            s = s[:i] + f'(s32)(({inner}) >> 32)' + s[j:]
        for c in callees:
            s = re.sub(rf'^(?:extern )?(?:M2C_UNK|s32|u32|void|\?) ({re.escape(c)}\()', r's64 \1', s, flags=re.M)
        out.append(('second-reg s64', s))
    # m2c pointer scaling (session 11: 6 of 10 hand matches): `M2C_UNK *p; p += 0x5C` / `s32 *p; p += 8` scale by the
    # pointee, the target adds BYTES -> retype the local to `u8 *` (casts on its assignments), extern M2C_UNK data -> u8
    sp = re.search(r'^\w[\w \*]*? \**\w+\([^)]*\) \{\n', src, re.M)
    if sp:
        body0 = src[sp.end():]
        for mm in re.finditer(r'^    (?:M2C_UNK|s32|u32|s16|u16|void) \*(\w+);$', body0, re.M):
            v = mm.group(1)
            if not re.search(rf'\b{v} [+-]?= (?:0x[0-9A-Fa-f]+|\d+);|\b{v} = \w+ [+-] ', body0): continue
            b = re.sub(rf'^    (?:M2C_UNK|s32|u32|s16|u16|void) \*{v};$', f'    u8 *{v};', body0, flags=re.M)
            b = re.sub(rf'^(\s+{v} = )(?!\(u8 \*\))([^;]+);', r'\1(u8 *)(\2);', b, flags=re.M)
            out.append((f'ptr-u8 {v}', src[:sp.end()] + b))
    # session 11b: `x >> 5` on an unsigned -> `x / 32` (stops cmp reusing a shifted reg: cmp r0,r4,lsr #5)
    for mm in re.finditer(r'\(u32\) (\w+) >> (\d)\b|\((?:u32|\(u32\) \w+)\) >> (\d)\b', src):
        if mm.group(1):
            out.append((f'shift-div @{mm.start()}', src[:mm.start()] + f'(u32) {mm.group(1)} / {1 << int(mm.group(2))}' + src[mm.end():]))
    # `if (call(..)->field == a)` / `if (M2C_FIELD(..) == a)`: hoist the load into a local first (flips cmp operand order)
    for mm in re.finditer(r'^(\s+)if \(((?:M2C_FIELD|\w+)\((?:[^()]|\([^()]*\))*\)(?:[^()=!<>]*)?) (==|!=) (\w+)\) \{', src, re.M):
        if 'M2C_FIELD' not in mm.group(2): continue
        for ty in ('s32', 'u8'):
            out.append((f'cmp-hoist {ty} @{mm.start()}', src[:mm.start()] + f'{mm.group(1)}{ty} hunt_v = {mm.group(2)};\n{mm.group(1)}if (hunt_v {mm.group(3)} {mm.group(4)}) {{' + src[mm.end():] ))
        break
    # goto loop -> do/while and for (session 11: 5 matches needed `for (i = 0; i < N; i++) { if (..) break; }`)
    for mm in re.finditer(r'^(\s*)(loop_\d+):\n((?:.*\n)*?)[ \t]*if \(([^\n]*)\) goto \2;\n', src, re.M):
        ws, body_, cond = mm.group(1), mm.group(3), mm.group(4)
        if re.search(r'^\s*\w+:$', body_, re.M): continue
        out.append((f'do-while {mm.group(2)}', src[:mm.start()] + f'{ws}do {{\n{body_}{ws}}} while ({cond});\n' + src[mm.end():]))
        inc = re.search(r'^\s*(\w+) \+= 1;\n$', body_, re.M)
        pre = re.search(rf'^\s*({inc.group(1)}) = (-?\w+);\n$', src[:mm.start()], re.M) if inc else None
        if inc and pre and pre.end() == mm.start():
            v = inc.group(1); b2 = body_[:inc.start()] + body_[inc.end():]
            out.append((f'for {mm.group(2)}', src[:pre.start()] + f'{ws}for ({v} = {pre.group(2)}; {cond}; {v}++) {{\n{b2}{ws}}}\n' + src[mm.end():]))
    # virtual call that also forwards the object: o->vt->f(&x, o)  (m2c drops the second `this`)
    for mm in re.finditer(r'\(\*\(([\w \*]+) \(\*\*\)\(([^)]*)\)\)\(\*\(u8 \*\*\)(\w+) \+ (0x[0-9A-Fa-f]+|\d+)\)\)\(([^()]*)\)', src):
        o = mm.group(3)
        if re.search(rf'\b{o}\b', mm.group(5).split(',', 1)[-1]) and ',' in mm.group(5): continue
        new = f'(*({mm.group(1)} (**)({mm.group(2)}, void *))(*(u8 **){o} + {mm.group(4)}))({mm.group(5)}, {o})'
        out.append((f'vcall-this2 {o}', src[:mm.start()] + new + src[mm.end():]))
    # unused leading param (callback ends up in r1): add `s32 arg_pad` first
    mm = re.search(r'^(\w[\w \*]*? \**\w+)\(([^)]*)\) \{$', src, re.M)
    if mm and mm.group(2).strip() not in ('', 'void'):
        out.append(('pad-param', src[:mm.start()] + f'{mm.group(1)}(s32 hunt_pad, {mm.group(2)}) {{' + src[mm.end():]))
    for mm in re.finditer(r'^extern (?:M2C_UNK|s32|u32) (data_\w+);$', src, re.M):
        out.append((f'extern-u8 {mm.group(1)}', src.replace(mm.group(0), f'extern u8 {mm.group(1)};')))
    return out


# ------------------------------------------------------------------ commands
def find_c(name, given=None):
    if given: return Path(given)
    for p in (BEST / f'{name}.c', ROOT / 'build' / 'auto' / 'near' / f'{name}.c', ROOT / 'build' / 'drafts' / f'{name}.c'):
        if p.exists(): return p
    return None


def battery(pool, name, src, rounds, log=print, all_profiles=True):
    """greedy hill climb over profiles then single mutations -> (best result, best source, trail of steps)."""
    t0 = time.time()
    seq = pool is None  # inside a sweep worker: judge one after the other (the sweep runs functions in parallel)
    pmap = (lambda f, jobs, chunksize=1: list(map(f, jobs))) if seq else pool.map
    profs = _profiles_job(name) if seq else pool.apply(_profiles_job, (name,))
    if not all_profiles: profs = profs[:6]
    res = pmap(_judge, [(name, src, pr) for pr in profs])
    order = sorted(range(len(profs)), key=lambda i: score(res[i]))
    best_src, best = src, res[order[0]]
    top = [profs[i] for i in order[:2] if res[i]['status'] in ('near', 'size', 'match')] or [profs[order[0]]]
    log(f'profiles: best {best["profile"]} -> {best["status"]} {best.get("diffs")}  '
        f'(next {", ".join(f"{profs[i]}={score(res[i])}" for i in order[1:4])})')
    trail = [f'profile {best["profile"]}']
    for rnd in range(rounds):
        if best.get('match'): break
        muts = mutations(best_src, name)
        if not muts: break
        jobs = [(name, s, pr) for _, s in muts for pr in top]
        rs = pmap(_judge, jobs, chunksize=2)
        k = min(range(len(rs)), key=lambda i: score(rs[i]))
        tag = muts[k // len(top)][0]
        log(f'round {rnd + 1}: {len(jobs)} variants, best {tag} -> {rs[k]["status"]} {rs[k].get("diffs")} '
            f'({rs[k]["profile"]}) [{time.time() - t0:.0f}s]')
        if score(rs[k]) >= score(best): break
        best_src, best = jobs[k][1], rs[k]; trail.append(tag)
        top = list(dict.fromkeys([best['profile']] + top))[:2]
    return best, best_src, trail


def record(name, best, best_src, trail, what='try'):
    """ledger + best/NAME.c; returns the parked reason (auto-park after BUDGET runs without a match)."""
    BEST.mkdir(parents=True, exist_ok=True)
    e = load().get(name, {})
    if best.get('match') or e.get('best') is None or score(best) < e.get('score', 10 ** 9):
        (BEST / f'{name}.c').write_text(best_src, encoding='utf-8', newline='\n')
    tries = e.get('tries', 0) + 1
    parked = None if best.get('match') else (e.get('parked') or (f'auto: {tries} try runs' if tries >= BUDGET else None))
    sc = min(score(best), e.get('score', 10 ** 9)) if not best.get('match') else 0
    update(name, tries=tries, best=best.get('diffs'), status=best['status'], profile=best['profile'], score=sc,
           parked=parked, note=f'{what}: {best["status"]} {best.get("diffs")} via {" + ".join(trail)}')
    return parked


def cmd_try(a):
    name = a.name
    p = find_c(name, a.file)
    with Pool(a.j, initializer=_init, initargs=(True,)) as pool:
        if p is None:
            _init(); _module(name); d, _ = WB.starting_draft(name); src = d or ''
        else: src = p.read_text(encoding='utf-8', errors='replace')
        best, best_src, trail = battery(pool, name, src, a.rounds, log=lambda m: print(m, flush=True))
    if not best.get('match') and best['status'] != 'compile':
        _init(); best = dict(best, **{k: v for k, v in _judge((name, best_src, best['profile'])).items() if k == 'diff'})
    parked = record(name, best, best_src, trail)
    if best.get('match'):
        print(f'MATCH {name} profile "{best["profile"]}" -> {BEST / (name + ".c")}')
        mark_matched(name, best_src, best['profile'])
        if a.submit: submit(name, BEST / f'{name}.c', best['profile'])
    else:
        print(f'best {best["status"]} {best.get("diffs")} ({best["profile"]}) -> {BEST / (name + ".c")}'
              + (f'  [PARKED: {parked}]' if parked else ''))
        print('\n'.join(l for l in (best.get('diff') or best.get('errors') or '').split('\n')
                        if ' * ' in l[:6] or 'TARGET' in l or best['status'] == 'compile')[:2000])


MATCHED = HUNT / 'matched'  # results.json + NAME.c: `python tools/workbench.py submit-many build/hunt/matched`


def mark_matched(name, src, prof):
    MATCHED.mkdir(parents=True, exist_ok=True)
    (MATCHED / f'{name}.c').write_text(src, encoding='utf-8', newline='\n')
    f = MATCHED / 'results.json'
    try: res = json.loads(f.read_text(encoding='utf-8'))
    except (OSError, ValueError): res = {}
    res[name] = {'status': 'match', 'match': True, 'profile': prof, 'k': [0, 0], 'mt': time.time()}
    f.write_text(json.dumps(res, indent=1), encoding='utf-8')


def cmd_sweep(a):
    """battery on the queue head, several functions at once (one per worker): mechanical work in the
    background while the session thinks. Matches -> build/hunt/matched (submit-many), never submitted here."""
    led, have, sizes = load(), matched_names(), unmatched_sizes()
    rows = [r for r in ranked(a, led, have, sizes) if (a.retry or r[2].get('tries', 0) == 0) and r[0] <= a.max_score][:a.n]
    print(len(rows), 'functions to sweep', flush=True)
    t0, nm = time.time(), 0
    jobs = [(name, (BEST / f'{name}.c').read_text(encoding='utf-8', errors='replace'), a.rounds) for _, name, _ in rows]
    prev = {name: e.get('best') for _, name, e in rows}
    # one function per worker (all cores busy; variants of one function are too few to fill 16 threads);
    # the parent is the only writer of the ledger and of matched/
    with Pool(a.j, initializer=_init, initargs=(True,)) as pool:
        for k, (name, out) in enumerate(pool.imap_unordered(_sweep_one, jobs)):
            if isinstance(out, str): print(name, 'error', out, flush=True); continue
            best, best_src, trail = out
            record(name, best, best_src, trail, what='sweep')
            if best.get('match'): nm += 1; mark_matched(name, best_src, best['profile'])
            print(f'[{k + 1}/{len(rows)} {time.time() - t0:.0f}s] {name} {prev[name]} -> {best["status"]} '
                  f'{best.get("diffs")} {" + ".join(trail[1:])}{"  MATCH" if best.get("match") else ""}', flush=True)
    print(f'{nm} matches -> {MATCHED} (python tools/workbench.py submit-many build/hunt/matched)')


def _sweep_one(job):
    name, src, rounds = job
    try: return name, battery(None, name, src, rounds, log=lambda m: None, all_profiles=False)
    except BaseException as ex: return name, str(ex)[:200]


def _profiles_job(name):
    try: return _profiles(name)
    except SystemExit as e: raise RuntimeError(str(e)) from None  # a SystemExit would kill the caller


def submit(name, path, prof):
    import subprocess
    r = subprocess.run([sys.executable, 'tools/workbench.py', 'submit', name, str(path), '--profile', prof,
                        '--who', 'claude'], capture_output=True, text=True)
    print('submit', (r.stdout or r.stderr)[-300:])


def cmd_import(a):
    dirs = a.dirs or (glob.glob(os.path.expandvars(r'%LOCALAPPDATA%\Temp\claude\*decomp*\*\scratchpad\**\results.json'),
                                recursive=True) + [str(HUNT / 'pool' / 'results.json')])
    have, led, n = matched_names(), load(), 0
    BEST.mkdir(parents=True, exist_ok=True)
    for f in dirs:
        f = Path(f); f = f / 'results.json' if f.is_dir() else f
        try: res = json.loads(f.read_text(encoding='utf-8'))
        except (OSError, ValueError): continue
        for name, r in res.items():
            if not isinstance(r, dict) or name in have or r.get('match'): continue
            c = f.parent / f'{name}.c'
            if not c.exists(): continue
            k = r.get('k') or [1, 9999]
            st = r.get('status', 'compile')
            sc = k[1] if st == 'near' else (300 + k[1] // 8 if st == 'size' else 10 ** 6 + RANK.get(st, 9))
            e = led.setdefault(name, {'tries': 0, 'notes': []})
            if sc < e.get('score', 10 ** 9):
                (BEST / f'{name}.c').write_bytes(c.read_bytes())
                e.update(score=sc, status=st, best=k[1] if st != 'compile' else None, profile=r.get('profile'),
                         size=r.get('size'), src=str(f.parent)); n += 1
    save(led)
    print(f'{n} better drafts imported from {len(dirs)} result files -> {BEST}')


def ranked(a, led, have, sizes):
    rows = []
    for name, e in led.items():
        if name in have or (e.get('parked') and not a.all) or name not in sizes: continue
        if a.max_size and sizes[name] > a.max_size: continue
        sc = e.get('score', 10 ** 6)
        rows.append((sc + 6 * e.get('tries', 0) + sizes[name] / 200, name, e))
    return sorted(rows)


def cmd_next(a):
    led, have, sizes = load(), matched_names(), unmatched_sizes()
    rows = ranked(a, led, have, sizes)
    sig = {}
    if a.rejudge:
        jobs = [(n, (BEST / f'{n}.c').read_text(encoding='utf-8', errors='replace'), e.get('profile'))
                for _, n, e in rows[:a.rejudge] if (BEST / f'{n}.c').exists()]
        with Pool(a.j, initializer=_init) as pool:
            for (n, _, _), r in zip(jobs, pool.map(_judge, jobs, chunksize=2)):
                e = led[n]; e['status'] = r['status']; e['best'] = r.get('diffs'); e['score'] = score(r)
                if r.get('match'): e['note_match'] = r['profile']
                pairs = re.findall(r'^\s*\d+ \* (\S+)[^|]*\|\s*(\S+)', r.get('diff') or '', re.M)
                sig[n] = ' '.join(f'{x}>{y}' for x, y in pairs[:6])
        save(led); rows = ranked(a, led, have, sizes)
    fam = {}
    for n, s in sig.items():
        if s: fam.setdefault(s, []).append(n)
    shown = set()
    print(f'{len(rows)} candidates ({sum(1 for e in led.values() if e.get("parked"))} parked). score name size status diffs tries profile | note')
    for sc, n, e in rows:
        if len(shown) >= a.n: break
        if n in shown: continue
        mates = [m for m in fam.get(sig.get(n), []) if m != n]
        tag = 'MATCH NOW ' if e.get('note_match') else ''
        print(f'{sc:7.1f} {tag}{n} {sizes[n]}B {e.get("status")} {e.get("best")} t{e.get("tries", 0)} '
              f'{e.get("profile") or ""} | {(e.get("notes") or [""])[-1][12:90]}')
        if mates: print(f'        family x{len(mates) + 1} [{sig[n][:70]}]: {" ".join(mates[:6])}')
        shown.add(n); shown.update(mates)


def cmd_show(a):
    e = load().get(a.name, {})
    print(json.dumps({k: v for k, v in e.items() if k != 'notes'}))
    for l in e.get('notes', []): print('  -', l)
    p = find_c(a.name)
    if p is None: print('no C yet (hunt.py try NAME makes it from the m2c draft)'); return
    src = p.read_text(encoding='utf-8', errors='replace')
    print(f'===== {p}'); print('\n'.join(l for l in src.split('\n') if l.strip() and not l.startswith('#include')))
    _init(); r = _judge((a.name, src, e.get('profile')))
    print(r['status'], r.get('profile'), 'diffs', r.get('diffs'), 'size', r.get('size'), '/', r.get('target_size'))
    print('\n'.join(l for l in (r.get('diff') or r.get('errors') or '').split('\n') if ' * ' in l[:6] or 'TARGET' in l or r['status'] == 'compile')[:2500])


# ------------------------------------------------------------------ siblings
FUNC = re.compile(r'^(\w+): ; 0x([0-9a-f]+)\n(.*?)^\s+(?:arm|thumb)_func_end \1$', re.S | re.M)


def shapes():
    """{name: (mnemonics, bl targets in order, pool symbols in order, matched?)} for every function of the build."""
    asm = ROOT / 'build' / project_version() / 'asm'
    cache = HUNT / 'shapes.json'
    newest = max((p.stat().st_mtime for p in asm.rglob('*.s')), default=0)
    if cache.exists() and cache.stat().st_mtime > newest:
        return json.loads(cache.read_text(encoding='utf-8'))
    out = {}
    for p in asm.rglob('*.s'):
        top = p.parent == asm
        for m in FUNC.finditer(p.read_text(encoding='utf-8', errors='replace')):
            body = m.group(3)
            mn = [l.split()[0] for l in body.split('\n') if l.startswith('    ') and l.split() and not l.split()[0].startswith('.')]
            bls = re.findall(r'^\s+blx?(?:eq|ne|lt|gt|le|ge|hi|ls|cc|cs|mi|pl)?\s+([A-Za-z_]\w*)\s*$', body, re.M)
            bs = re.findall(r'^\s+b(?:eq|ne|lt|gt|le|ge|hi|ls|cc|cs|mi|pl)?\s+([A-Za-z_]\w*)\s*$', body, re.M)
            words = re.findall(r'\.word\s+([A-Za-z_]\w*)', body)
            out[m.group(1)] = [mn, list(dict.fromkeys(bls + [b for b in bs if not b.startswith('_L')])),
                               list(dict.fromkeys(words)), not top]
    HUNT.mkdir(parents=True, exist_ok=True); cache.write_text(json.dumps(out), encoding='utf-8')
    return out


def project_version():
    import project
    return project.VERSION if hasattr(project, 'VERSION') else 'eu'


def transplant(src, frm, to, sh):
    a, b = sh[frm], sh[to]
    ren = {frm: to}
    for x, y in ((a[1], b[1]), (a[2], b[2])):
        if len(x) == len(y): ren.update({p: q for p, q in zip(x, y) if p != q})
    tok = {k: f'@@{i}@@' for i, k in enumerate(ren)}
    for k, t in sorted(tok.items(), key=lambda kv: -len(kv[0])): src = re.sub(rf'\b{re.escape(k)}\b', t, src)
    for k, t in tok.items(): src = src.replace(t, ren[k])
    # one declaration per symbol: the renamed externs can now repeat
    seen, lines = set(), []
    for l in src.split('\n'):
        if l.startswith('extern ') or re.match(r'^[\w ]+\**\s*\w+\([^)]*\);\s*(/\*.*\*/)?$', l):
            if l in seen: continue
            seen.add(l)
        lines.append(l)
    return '\n'.join(lines)


def cmd_sibs(a):
    sh = shapes()
    if a.name not in sh: sys.exit(f'{a.name}: not in the disassembly (ninja dis?)')
    srcf = ROOT / 'src' / 'auto' / f'{a.name}.c'
    if not srcf.exists(): srcf = find_c(a.name)
    if srcf is None: sys.exit('no C for ' + a.name)
    src = srcf.read_text(encoding='utf-8', errors='replace')
    mprof = re.match(r'/\* compiler: (.*?) \*/', src)
    src = re.sub(r'^/\* compiler: .*?\*/\n', '', src)
    mine = sh[a.name][0]; have = matched_names()
    sm = difflib.SequenceMatcher(None, [], mine, autojunk=False)  # b (cached side) = NAME, a = each candidate
    cands = []
    for n, (mn, _, _, done) in sh.items():
        if done or n == a.name or n in have or not (0.7 <= len(mn) / max(1, len(mine)) <= 1.4): continue
        sm.set_seq1(mn)
        if sm.real_quick_ratio() < a.min or sm.quick_ratio() < a.min: continue
        r = sm.ratio()
        if r >= a.min: cands.append((r, n))
    cands.sort(reverse=True); cands = cands[:a.n]
    if not cands: print('no sibling >=', a.min); return
    jobs = [(n, transplant(src, a.name, n, sh), mprof.group(1) if mprof else None) for _, n in cands]
    with Pool(a.j, initializer=_init) as pool: rs = pool.map(_judge, jobs)
    led = load(); BEST.mkdir(parents=True, exist_ok=True)
    for (sim, n), (_, s, _), r in sorted(zip(cands, jobs, rs), key=lambda x: score(x[2])):
        e = led.setdefault(n, {'tries': 0, 'notes': []})
        print(f'{sim:.2f} {n} {len(sh[n][0])} ins -> {r["status"]} {r.get("diffs")} ({r.get("profile")})')
        if score(r) < e.get('score', 10 ** 9):
            (BEST / f'{n}.c').write_text(s, encoding='utf-8', newline='\n')
            e.update(score=score(r), status=r['status'], best=r.get('diffs'), profile=r.get('profile'))
            e['notes'].append(time.strftime('%m-%d %H:%M ') + f'sibling of {a.name}: {r["status"]} {r.get("diffs")}')
            if r.get('match') and a.submit: submit(n, BEST / f'{n}.c', r['profile'])
    save(led)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest='cmd', required=True)
    p = sp.add_parser('import'); p.add_argument('dirs', nargs='*')
    p = sp.add_parser('next'); p.add_argument('-n', type=int, default=25); p.add_argument('--max-size', type=int)
    p.add_argument('--rejudge', type=int, default=0); p.add_argument('--all', action='store_true'); p.add_argument('-j', type=int, default=12)
    p = sp.add_parser('show'); p.add_argument('name')
    p = sp.add_parser('try'); p.add_argument('name'); p.add_argument('file', nargs='?')
    p.add_argument('--rounds', type=int, default=4); p.add_argument('-j', type=int, default=12); p.add_argument('--submit', action='store_true')
    p = sp.add_parser('sweep'); p.add_argument('-n', type=int, default=100); p.add_argument('--max-score', type=float, default=40)
    p.add_argument('--rounds', type=int, default=2); p.add_argument('-j', type=int, default=15)
    p.add_argument('--max-size', type=int); p.add_argument('--all', action='store_true')
    p.add_argument('--retry', action='store_true', help='also functions already tried (not parked): after new mutations')
    p = sp.add_parser('sibs'); p.add_argument('name'); p.add_argument('-n', type=int, default=12)
    p.add_argument('--min', type=float, default=0.80); p.add_argument('-j', type=int, default=12); p.add_argument('--submit', action='store_true')
    for c in ('note', 'park'):
        p = sp.add_parser(c); p.add_argument('name'); p.add_argument('text'); p.add_argument('--re', action='store_true')
    p = sp.add_parser('unpark'); p.add_argument('name')
    a = ap.parse_args()
    if a.cmd == 'note': print(update(a.name, note=a.text)['notes'][-1])
    elif a.cmd == 'park' and a.re:  # every ledger name matching the regex (e.g. a whole family / module)
        led = load(); ns = [n for n in led if re.fullmatch(a.name, n) and not led[n].get('parked')]
        for n in ns: led[n]['parked'] = a.text; led[n]['notes'].append(time.strftime('%m-%d %H:%M ') + 'parked: ' + a.text)
        save(led); print('parked', len(ns))
    elif a.cmd == 'park': update(a.name, parked=a.text, note='parked: ' + a.text); print('parked', a.name)
    elif a.cmd == 'unpark':
        led = load(); led.get(a.name, {}).pop('parked', None); led.get(a.name, {})['tries'] = 0; save(led); print('unparked', a.name)
    else: globals()['cmd_' + a.cmd](a)


if __name__ == '__main__':
    main()
    # multiprocessing.Pool sometimes hangs at exit on Windows (workers stuck on a pipe): the ledger is saved, leave now
    sys.stdout.flush(); sys.stderr.flush(); os._exit(0)
