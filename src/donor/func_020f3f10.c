/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02073ef4 from projets/nintendogs-dachshund/src/donor/func_02073ef4.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
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
typedef struct UnkResTexInfo {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
} UnkResTexInfo;
typedef struct UnkResTex4x4Info {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
    u32 unk_10;
} UnkResTex4x4Info;
typedef struct UnkResPlttInfo {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
} UnkResPlttInfo;
typedef struct UnkResTex {
    u32 unk_00;
    u32 unk_04;
    UnkResTexInfo unk_08;
    UnkResTex4x4Info unk_18;
    UnkResPlttInfo unk_2c;
    UnkResDict unk_3c;
} UnkResTex;
typedef struct UnkResDictPlttData {
    u16 unk_00;
    u16 unk_02;
} UnkResDictPlttData;
typedef struct UnkResDictToMatIdxData {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
} UnkResDictToMatIdxData;
typedef struct UnkResMat {
    u16 unk_00;
    u16 unk_02;
    UnkResDict unk_04;
} UnkResMat;
typedef struct UnkResMatData {
    u8 unk_00[0x14];
    u32 unk_14;
    u8 unk_18[4];
    u16 unk_1c;
    u16 unk_1e;
    u16 unk_20;
    u16 unk_22;
    s32 unk_24;
    s32 unk_28;
} UnkResMatData;
static inline void *GetResDataByIdx(const UnkResDict *dict, int idx) {
    UnkResDictEntryHeader *hdr = (UnkResDictEntryHeader *) ((u8 *) dict + dict->unk_06);
    return (u8 *) hdr->unk_04 + hdr->unk_00 * idx;
}
static inline UnkResMatData *GetMatDataByIdx(UnkResMat *mat, int idx) {
    return (UnkResMatData *) ((u8 *) mat + *(u32 *) GetResDataByIdx(&mat->unk_04, idx));
}
void func_020f3f10(UnkResMat *mat, UnkResDictToMatIdxData *data, UnkResTex *tex, UnkResDictPlttData *plttData) {
    u8 *idx        = (u8 *) mat + data->unk_00;
    u16 plttBase   = plttData->unk_00;
    u16 vramOffset = (((tex->unk_2c.unk_00) & 0xffff) << 3) >> 3;
    u32 i;

    if (!(plttData->unk_02 & 1)) {
        plttBase >>= 1;
        vramOffset >>= 1;
    }
    for (i = 0; i < data->unk_02; i++) {
        UnkResMatData *matData = GetMatDataByIdx(mat, idx[i]);

        matData->unk_1c = (u16) (plttBase + vramOffset);
    }
    data->unk_03 |= 1;
}
