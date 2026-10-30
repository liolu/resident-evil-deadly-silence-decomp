/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207a398 from projets/nintendogs-dachshund/src/donor/func_0207a398.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;
typedef long fx32;
typedef s16 fx16;
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
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} UnkResDict;
typedef struct {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} UnkResDictEntryHeader;
typedef struct {
    u8 category0;
    u8 revision;
    u16 category1;
    u16 numFrame;
    u16 flag;
    UnkResDict dict;
} UnkResAnm;
static inline void *UnkGetResDataByIdx_(const UnkResDict *dict, u32 idx) {
    const UnkResDictEntryHeader *p = (const UnkResDictEntryHeader *) ((const u8 *) dict + dict->ofsEntry);
    return (void *) (&p->data[0] + p->sizeUnit * idx);
}
typedef struct {
    u32 scaleSInfo;
    u32 scaleSData;
    u32 scaleTInfo;
    u32 scaleTData;
    u32 rotInfo;
    u32 rotData;
    u32 transSInfo;
    u32 transSData;
    u32 transTInfo;
    u32 transTData;
} UnkTexSRTAnmData;
extern fx32 func_020fa9a0(const u8 *p, u32 info, u32 data, u32 frame);
extern u32 func_020fa894(const u8 *pData, u32 info, u32 data, u32 frame);
void func_020fa794(const UnkResAnm *anm, u32 dataIdx, u32 frame, UnkMatAnmResult *result) {
    const UnkTexSRTAnmData *data = UnkGetResDataByIdx_(&anm->dict, dataIdx);
    u32 flag                     = result->flag;
    fx32 s, t;
    u32 rot;

    s = func_020fa9a0((const u8 *) anm, data->transSInfo, data->transSData, frame);
    t = func_020fa9a0((const u8 *) anm, data->transTInfo, data->transTData, frame);
    if (s == 0 && t == 0) {
        flag |= 4;
    } else {
        result->transS = s;
        result->transT = t;
        flag &= ~4;
    }

    rot = func_020fa894((const u8 *) anm, data->rotInfo, data->rotData, frame);
    if (rot == 0x10000000) {
        flag |= 2;
    } else {
        result->sinR = (fx16) rot;
        result->cosR = (fx16) (rot >> 16);
        flag &= ~2;
    }

    s = func_020fa9a0((const u8 *) anm, data->scaleSInfo, data->scaleSData, frame);
    t = func_020fa9a0((const u8 *) anm, data->scaleTInfo, data->scaleTData, frame);
    if (s == 0x1000 && t == 0x1000) {
        flag |= 1;
    } else {
        result->scaleS = s;
        result->scaleT = t;
        flag &= ~1;
    }

    result->flag = flag;
}
