/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206b6b0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_anmblend.c (license: none),
 * reused by tools/donor_match.py */
typedef signed long intptr_t;
typedef unsigned long uintptr_t;
typedef intptr_t ptrdiff_t;
typedef unsigned long size_t;
typedef unsigned short wchar_t;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long s64;
typedef int s32;
typedef short s16;
typedef char s8;
typedef float f32;
typedef double f64;
typedef volatile u64 vu64;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef volatile u8 vu8;
typedef volatile s64 vs64;
typedef volatile s32 vs32;
typedef volatile s16 vs16;
typedef volatile s8 vs8;
typedef volatile f32 vf32;
typedef volatile f64 vf64;
typedef s32 BOOL;
typedef struct UnkResAnmHeader {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
} UnkResAnmHeader;
struct UnkAnmObj;
typedef void (*UnkAnmFunc)(void *result, struct UnkAnmObj *anm, u32 dataIdx);
typedef struct UnkAnmObj {
    s32 unk_00;
    s32 unk_04;
    UnkResAnmHeader *unk_08;
    UnkAnmFunc unk_0c;
    struct UnkAnmObj *unk_10;
    void *unk_14;
    u8 unk_18;
    u8 unk_19;
    u16 unk_1a[1];
} UnkAnmObj;
typedef struct UnkResMdlInfo {
    u8 unk_00[0x17];
    u8 unk_17;
    u8 unk_18;
} UnkResMdlInfo;
typedef BOOL (*UnkBlendFunc)(void *result, UnkAnmObj *anm, u32 id);
typedef void (*UnkAnmInitFunc)(UnkAnmObj *anm, void *resAnm, const UnkResMdlInfo *resMdl);
typedef struct UnkAnmInitEntry {
    u8 unk_00;
    u16 unk_02;
    UnkAnmInitFunc unk_04;
} UnkAnmInitEntry;
typedef struct UnkRenderObj {
    u32 unk_00;
    void *unk_04;
    UnkAnmObj *unk_08;
    UnkBlendFunc unk_0c;
    UnkAnmObj *unk_10;
    UnkBlendFunc unk_14;
    UnkAnmObj *unk_18;
    UnkBlendFunc unk_1c;
    u8 unk_20[0x1c];
    u32 unk_3c[2];
    u32 unk_44[2];
    u32 unk_4c[2];
} UnkRenderObj;
typedef struct UnkVecFx32 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} UnkVecFx32;
typedef struct UnkJntAnmResult {
    u32 unk_00;
    UnkVecFx32 unk_04;
    UnkVecFx32 unk_10;
    UnkVecFx32 unk_1c;
    UnkVecFx32 unk_28;
    UnkVecFx32 unk_34;
    UnkVecFx32 unk_40;
    UnkVecFx32 unk_4c;
} UnkJntAnmResult;
extern void MI_CpuFill(u32 value, void *dest, u32 size);
extern s32 FX_Divide(s32 numer, s32 denom);
extern void func_02063008(const UnkVecFx32 *a, const UnkVecFx32 *b, UnkVecFx32 *axb);
extern void func_020630ec(const UnkVecFx32 *src, UnkVecFx32 *dst);
BOOL func_0206b308(void *result, UnkAnmObj *anm, int matID);
void func_0206b358(UnkVecFx32 *dst, const UnkVecFx32 *src, s32 ratio, u32 isOne);
BOOL func_0206b3c8(UnkJntAnmResult *result, UnkAnmObj *anm, int jntID);
BOOL func_020f4ed8(u32 *result, UnkAnmObj *anm, int nodeID) {
    BOOL ret;

    *result = 0;
    ret     = 0;
    do {
        if (anm->unk_1a[nodeID] & 0x100) {
            u32 r;

            anm->unk_0c(&r, anm, anm->unk_1a[nodeID] & 0xff);
            *result |= r;
            ret = 1;
        }
        anm = anm->unk_10;
    } while (anm != 0);
    return ret;
}
extern void func_02070258(void *result, UnkAnmObj *anm, u32 dataIdx);
extern void func_020708a8(void *result, UnkAnmObj *anm, u32 dataIdx);
extern void func_020706ac(void *result, UnkAnmObj *anm, u32 dataIdx);
extern void func_0206ea74(void *result, UnkAnmObj *anm, u32 dataIdx);
extern void func_02070968(void *result, UnkAnmObj *anm, u32 dataIdx);
extern void func_020701c0(UnkAnmObj *anm, void *resAnm, const UnkResMdlInfo *resMdl);
extern void func_020706f0(UnkAnmObj *anm, void *resAnm, const UnkResMdlInfo *resMdl);
extern void func_02070614(UnkAnmObj *anm, void *resAnm, const UnkResMdlInfo *resMdl);
extern void func_0207091c(UnkAnmObj *anm, void *resAnm, const UnkResMdlInfo *resMdl);
extern void func_0206e9f8(UnkAnmObj *anm, void *resAnm, const UnkResMdlInfo *resMdl);
extern UnkBlendFunc data_020c3de0;
extern UnkBlendFunc data_020c3ddc;
extern UnkBlendFunc data_020c3dd8;
extern UnkAnmFunc data_020c3dd4;
extern UnkAnmFunc data_020c3dd0;
extern UnkAnmFunc data_020c3dcc;
extern UnkAnmFunc data_020c3dc8;
extern UnkAnmFunc data_020c3dc4;
extern u32 data_020c3dc0;
extern UnkAnmInitEntry data_020c3de4[10];
