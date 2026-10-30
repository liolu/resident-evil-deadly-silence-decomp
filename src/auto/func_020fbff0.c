/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02071958 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_3dsmax.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef long long s64;
typedef short s16;
typedef long fx32;
typedef s16 fx16;
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
void func_020fbff0(UnkMtxFx44 *m, const UnkMatAnmResult *anm) {
    fx32 tS;
    fx32 tT;

    m->m[0][0] = anm->scaleS;
    m->m[1][1] = anm->scaleT;
    m->m[0][1] = 0;
    tS         = (-anm->origW << 11) - anm->transS * anm->origW;
    tT         = anm->transT * anm->origH + (-anm->origH << 11);
    m->m[3][0] = ((fx32) (((s64) (anm->scaleS) * (tS)) >> 8)) + (anm->origW << 15);
    m->m[3][1] = ((fx32) (((s64) (anm->scaleT) * (tT)) >> 8)) + (anm->origH << 15);
    m->m[1][0] = 0;
}
