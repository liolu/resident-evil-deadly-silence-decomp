/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02071b18 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_3dsmax.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef long long s64;
typedef short s16;
typedef long fx32;
typedef s16 fx16;
extern void func_020feabc(fx32 numer, fx32 denom);
extern fx32 func_020feb5c(void);
typedef struct {
    fx32 m[4][4];
} UnkMtxFx44;
typedef struct {
    u32 flag;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmTexImage;
    u32 prmTexPltt;
    fx32 scaleS;
    fx32 scaleT;
    fx16 sinR;
    fx16 cosR;
    fx32 transS;
    fx32 transT;
    u16 origW;
    u16 origH;
    fx32 magW;
    fx32 magH;
} UnkMatAnmResult;
void func_020fbdc0(UnkMtxFx44 *m, const UnkMatAnmResult *anm) {
    fx32 w = anm->origW << 12;
    fx32 h = anm->origH << 12;
    fx32 tS;
    fx32 tT;

    func_020feabc(h, w);
    m->m[0][0] = anm->cosR;
    m->m[1][1] = anm->cosR;
    m->m[0][1] = (anm->sinR * func_020feb5c()) >> 12;
    func_020feabc(w, h);
    tS         = -anm->origW << 11;
    tT         = -anm->origH << 11;
    m->m[3][0] = (fx32) (((s64) anm->cosR * tS - (s64) anm->sinR * tT) >> 8) + (anm->origW << 15);
    m->m[3][1] = (fx32) (((s64) anm->sinR * tS + (s64) anm->cosR * tT) >> 8) + (anm->origH << 15);
    m->m[1][0] = (-anm->sinR * func_020feb5c()) >> 12;
}
