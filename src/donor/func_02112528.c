/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* strcmp from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/msl/strcmp.c (license: CC0-1.0), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02112528(const char *a, const char *b);
int func_02112528(const char *a, const char *b) {
    u32 va;
    u32 vb;
    u32 misalign;
    int delta;

    va    = *(u8 *) a;
    vb    = *(u8 *) b;
    delta = va - vb;
    if (delta != 0) {
        return delta;
    }

    misalign = (u32) a & 3;
    if (((u32) b & 3) != misalign) {
        goto bytes;
    }

    if (misalign != 0) {
        if (va == 0) {
            return 0;
        }
        for (misalign = 3 - misalign; misalign != 0; misalign--) {
            va    = *(u8 *) ++a;
            vb    = *(u8 *) ++b;
            delta = va - vb;
            if (delta != 0) {
                return delta;
            }
            if (va == 0) {
                return 0;
            }
        }
        a++;
        b++;
    }

    va = *(u32 *) a;
    vb = *(u32 *) b;
    if (((((va) + 0xFEFEFEFF) & 0x80808080) == 0)) {
        while (va == vb) {
            va = *(u32 *) (a += 4);
            vb = *(u32 *) (b += 4);
            if (!((((va) + 0xFEFEFEFF) & 0x80808080) == 0)) {
                goto last_word;
            }
        }
        a--;
        b--;
        goto bytes;
    }

last_word:
    va    = *(u8 *) a;
    vb    = *(u8 *) b;
    delta = va - vb;
    if (delta != 0) {
        return delta;
    }

bytes:
    if (va == 0) {
        return 0;
    }
    do {
        va    = *(u8 *) ++a;
        vb    = *(u8 *) ++b;
        delta = va - vb;
        if (delta != 0) {
            return delta;
        }
    } while (va != 0);
    return 0;
}
