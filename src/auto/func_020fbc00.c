/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02071c64 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_3dsmax.c (license: none),
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
typedef struct {
    u32 cmd;
    u32 mtxMode;
    UnkMtxFx44 m;
    u32 mtxMode2;
} UnkTexMtxCmd;
typedef void (*UnkCalcTexMtxFunc)(UnkMtxFx44 *m, const UnkMatAnmResult *anm);
extern void func_020f7b18(u32 op, const void *args, u32 num);
extern UnkCalcTexMtxFunc data_02136b48[8];
void func_020fbc00(const UnkMatAnmResult *anm) {
    UnkTexMtxCmd buf;

    if (anm->flag & 8) {
        buf.cmd = 0x101610;
    } else {
        buf.cmd = 0x101810;
    }
    buf.mtxMode   = 3;
    buf.mtxMode2  = 2;
    buf.m.m[3][2] = 0;
    buf.m.m[2][3] = 0;
    buf.m.m[2][2] = 0;
    buf.m.m[2][1] = 0;
    buf.m.m[2][0] = 0;
    buf.m.m[1][3] = 0;
    buf.m.m[1][2] = 0;
    buf.m.m[0][3] = 0;
    buf.m.m[0][2] = 0;
    buf.m.m[3][3] = 0x1000;

    data_02136b48[anm->flag & 7](&buf.m, anm);

    if (anm->magW != 0x1000) {
        buf.m.m[0][0] = ((fx32) (((s64) (anm->magW) * (buf.m.m[0][0])) >> 12));
        buf.m.m[0][1] = ((fx32) (((s64) (anm->magW) * (buf.m.m[0][1])) >> 12));
        buf.m.m[3][0] = ((fx32) (((s64) (anm->magW) * (buf.m.m[3][0])) >> 12));
    }
    if (anm->magH != 0x1000) {
        buf.m.m[1][0] = ((fx32) (((s64) (anm->magH) * (buf.m.m[1][0])) >> 12));
        buf.m.m[1][1] = ((fx32) (((s64) (anm->magH) * (buf.m.m[1][1])) >> 12));
        buf.m.m[3][1] = ((fx32) (((s64) (anm->magH) * (buf.m.m[3][1])) >> 12));
    }

    func_020f7b18(buf.cmd, (u32 *) &buf + 1, 0x12);
}
