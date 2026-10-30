/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020780c4 from projets/nintendogs-dachshund/src/donor/func_020780c4.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef s32 fx32;
typedef struct NNSG3dResDict {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 unk_04;
    u16 ofsEntry;
} NNSG3dResDict;
typedef struct UnkResDictEntryHeader {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} UnkResDictEntryHeader;
static inline void *GetResDataByIdx(const NNSG3dResDict *dict, u32 idx) {
    UnkResDictEntryHeader *p = (UnkResDictEntryHeader *) ((u8 *) dict + dict->ofsEntry);
    return (void *) ((u8 *) &p->data[0] + p->sizeUnit * idx);
}
typedef struct NNSG3dResMdlInfo {
    u8 sbcType;
    u8 scalingRule;
    u8 texMtxMode;
    u8 numNode;
    u8 numMat;
    u8 numShp;
    u8 unk_06;
    u8 unk_07;
    fx32 posScale;
    fx32 invPosScale;
    u8 unk_10[0x2c - 0x10];
} NNSG3dResMdlInfo;
typedef struct NNSG3dResMdl {
    u32 size;
    u32 ofsSbc;
    u32 ofsMat;
    u32 ofsShp;
    u32 ofsEvpMtx;
    NNSG3dResMdlInfo info;
    NNSG3dResDict nodeInfo;
} NNSG3dResMdl;
typedef struct NNSG3dResMat {
    u16 unk_00;
    u16 unk_02;
    NNSG3dResDict dict;
} NNSG3dResMat;
typedef struct NNSG3dResMatData {
    u16 itemTag;
    u16 size;
    u32 diffAmb;
    u32 specEmi;
    u32 polyAttr;
    u32 polyAttrMask;
    u32 texImageParam;
    u32 unk_18;
    u16 texPlttBase;
    u16 flag;
    u16 origWidth;
    u16 origHeight;
    fx32 magW;
    fx32 magH;
    u8 texMtx[4];
} NNSG3dResMatData;
static inline NNSG3dResMatData *GetMatDataByIdx(const NNSG3dResMat *mat, u32 idx) {
    const u32 *p = (const u32 *) GetResDataByIdx(&mat->dict, idx);
    return (NNSG3dResMatData *) ((u8 *) mat + *p);
}
static inline NNSG3dResMat *GetMat(const NNSG3dResMdl *mdl) {
    return (NNSG3dResMat *) ((u8 *) mdl + mdl->ofsMat);
}
void func_020f8480(NNSG3dResMdl *mdl, u32 matID, u32 alpha) {
    NNSG3dResMatData *data = GetMatDataByIdx(GetMat(mdl), matID);
    data->polyAttr         = (data->polyAttr & ~0x1f0000) | (alpha << 16);
}
