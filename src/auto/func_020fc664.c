/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02071fe0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_xsi.c (license: none), reused
 * by tools/donor_match.py */
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
void func_020fc664(UnkMtxFx44 *m, const UnkMatAnmResult *anm) {
    fx32 a;
    fx32 b;

    m->m[0][0] = anm->scaleS;
    m->m[1][1] = anm->scaleT;
    m->m[0][1] = 0;
    a          = ((fx32) (((s64) (anm->transS) * (anm->scaleS)) >> 12));
    b          = ((fx32) (((s64) (-anm->transT) * (anm->scaleT)) >> 12));
    m->m[3][0] = (anm->origW * -a) << 4;
    m->m[3][1] = (-anm->origH * (anm->scaleT + b - 0x1000)) << 4;
    m->m[1][0] = 0;
}
