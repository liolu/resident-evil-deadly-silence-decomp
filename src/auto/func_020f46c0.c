/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206a2bc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_kernel.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef struct UnkResAnmHeader {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
} UnkResAnmHeader;
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
typedef void (*UnkAnmInitFunc)(UnkAnmObj *anm, void *resAnm, const UnkResMdlInfo *resMdl);
typedef struct UnkAnmInitEntry {
    u8 unk_00;
    u16 unk_02;
    UnkAnmInitFunc unk_04;
} UnkAnmInitEntry;
extern u32 data_0213690c;
extern UnkAnmInitEntry data_02136930[];
void func_020f46c0(UnkAnmObj *anm, UnkResAnmHeader *resAnm, const UnkResMdlInfo *resMdl, void *resTex) {
    u32 i;

    anm->unk_00 = 0;
    anm->unk_08 = resAnm;
    anm->unk_10 = 0;
    anm->unk_18 = 127;
    anm->unk_04 = 0x1000;
    anm->unk_14 = resTex;

    for (i = 0; i < data_0213690c; i++) {
        if (resAnm->unk_00 == data_02136930[i].unk_00 && resAnm->unk_02 == data_02136930[i].unk_02) {
            data_02136930[i].unk_04(anm, resAnm, resMdl);
            return;
        }
    }
}
