/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0206ae08 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_glbstate.c (license: none),
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
void func_020f4d04(const UnkVecFx32 *trans) {
    data_021543a4.unk_e0 = *trans;
    data_021543a4.unk_fc &= ~0xa4;
}
