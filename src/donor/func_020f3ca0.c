/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206ac24 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_binres.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct UnkResDict {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
} UnkResDict;
typedef struct UnkResDictEntryHeader {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04[1];
} UnkResDictEntryHeader;
typedef struct UnkResMdl {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} UnkResMdl;
typedef struct UnkResMdlSet {
    u32 unk_00;
    u32 unk_04;
    UnkResDict unk_08;
} UnkResMdlSet;
typedef struct UnkResDictMdlSetData {
    u32 unk_00;
} UnkResDictMdlSetData;
static inline void *GetResDataByIdx(const UnkResDict *dict, int idx) {
    UnkResDictEntryHeader *hdr = (UnkResDictEntryHeader *) ((u8 *) dict + dict->unk_06);
    return (u8 *) hdr->unk_04 + hdr->unk_00 * idx;
}
void func_020f3fa8(UnkResMdl *mdl);
void func_020f3d8c(UnkResMdl *mdl);
void func_020f3ca0(UnkResMdlSet *mdlSet) {
    u32 i;

    for (i = 0; i < mdlSet->unk_08.unk_01; i++) {
        UnkResMdl *mdl =
            (UnkResMdl *) ((u8 *) mdlSet + ((UnkResDictMdlSetData *) GetResDataByIdx(&mdlSet->unk_08, i))->unk_00);

        func_020f3fa8(mdl);
        func_020f3d8c(mdl);
    }
}
