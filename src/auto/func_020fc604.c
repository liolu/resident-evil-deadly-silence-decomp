/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02072064 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_xsi.c (license: none), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
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
void func_020fc604(UnkMtxFx44 *m, const UnkMatAnmResult *anm) {
    fx32 tS;
    fx32 tT;

    m->m[0][0] = 0x1000;
    m->m[1][1] = 0x1000;
    m->m[0][1] = 0;
    tS         = -anm->transS;
    tT         = -anm->transT;
    m->m[3][0] = (anm->origW * tS) << 4;
    m->m[3][1] = (-anm->origH * tT) << 4;
    m->m[1][0] = 0;
}
