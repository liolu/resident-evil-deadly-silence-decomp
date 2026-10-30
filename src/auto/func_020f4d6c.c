/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206ac78 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_glbstate.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef struct UnkVecFx32 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} UnkVecFx32;
typedef struct UnkMtx33 {
    s32 unk_00[9];
} UnkMtx33;
typedef struct UnkMtx43 {
    s32 unk_00[12];
} UnkMtx43;
typedef struct UnkMtx44 {
    s32 unk_00[4][4];
} UnkMtx44;
typedef struct UnkG3dGlb {
    u32 unk_00;
    u32 unk_04;
    UnkMtx44 unk_08;
    u32 unk_48;
    UnkMtx43 unk_4c;
    u32 unk_7c;
    u32 unk_80[4];
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
    u32 unk_9c;
    u32 unk_a0;
    u32 unk_a4;
    u32 unk_a8[4];
    u32 unk_b8;
    UnkMtx33 unk_bc;
    UnkVecFx32 unk_e0;
    UnkVecFx32 unk_ec;
    u32 unk_f8;
    u32 unk_fc;
    UnkMtx43 unk_100;
    UnkMtx43 unk_130;
    UnkMtx43 unk_160;
    u8 unk_190[0x30];
    UnkMtx44 unk_1c0;
    UnkMtx44 unk_200;
    UnkVecFx32 unk_240;
    UnkVecFx32 unk_24c;
    UnkVecFx32 unk_258;
} UnkG3dGlb;
extern UnkG3dGlb data_021543a4;
extern void func_020fdcdc(UnkMtx33 *m);
extern void func_020fe034(UnkMtx43 *m);
extern void func_020fe738(UnkMtx44 *m);
void func_020f4d6c(void) {
    data_021543a4.unk_00 = 0x17101610;
    data_021543a4.unk_04 = 0;
    data_021543a4.unk_48 = 2;
    data_021543a4.unk_7c = 0x32323232;
    data_021543a4.unk_90 = 0x60293130;
    data_021543a4.unk_a4 = 0x33333333;
    data_021543a4.unk_b8 = 0x2a1b19;
    func_020fe034(&data_021543a4.unk_4c);
    func_020fe738(&data_021543a4.unk_08);
    data_021543a4.unk_80[0]     = 0x2d8b62d8;
    data_021543a4.unk_80[1]     = 0x40000200;
    data_021543a4.unk_80[2]     = 0x800001ff;
    data_021543a4.unk_80[3]     = 0xc0080000;
    data_021543a4.unk_94        = 0x4210c210;
    data_021543a4.unk_98        = 0x4210c210;
    data_021543a4.unk_9c        = 0x1f008f;
    data_021543a4.unk_a0        = 0xbfff0000;
    data_021543a4.unk_a8[0]     = 0x7fff;
    data_021543a4.unk_a8[1]     = 0x4000001f;
    data_021543a4.unk_a8[2]     = 0x800003e0;
    data_021543a4.unk_a8[3]     = 0xc0007c00;
    data_021543a4.unk_e0.unk_00 = 0;
    data_021543a4.unk_e0.unk_04 = 0;
    data_021543a4.unk_e0.unk_08 = 0;
    func_020fdcdc(&data_021543a4.unk_bc);
    data_021543a4.unk_ec.unk_00  = 0x1000;
    data_021543a4.unk_ec.unk_04  = 0x1000;
    data_021543a4.unk_ec.unk_08  = 0x1000;
    data_021543a4.unk_f8         = 0;
    data_021543a4.unk_fc         = 0;
    data_021543a4.unk_240.unk_08 = 0;
    data_021543a4.unk_240.unk_04 = 0;
    data_021543a4.unk_240.unk_00 = 0;
    data_021543a4.unk_24c.unk_08 = 0;
    data_021543a4.unk_24c.unk_00 = 0;
    data_021543a4.unk_24c.unk_04 = 0x1000;
    data_021543a4.unk_258.unk_04 = 0;
    data_021543a4.unk_258.unk_00 = 0;
    data_021543a4.unk_258.unk_08 = -0x1000;
}
