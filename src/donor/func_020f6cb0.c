/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020769c4 from projets/nintendogs-dachshund/src/donor/func_020769c4.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef short s16;
typedef s32 BOOL;
typedef s32 fx32;
typedef s16 fx16;
typedef struct {
    fx32 x, y, z;
} VecFx32;
typedef struct {
    fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22;
} MtxFx33;
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
typedef struct NNSG3dResShp {
    NNSG3dResDict dict;
} NNSG3dResShp;
typedef struct NNSG3dResShpData {
    u16 itemTag;
    u16 size;
    u32 flag;
    u32 ofsDL;
    u32 sizeDL;
} NNSG3dResShpData;
typedef struct NNSG3dMatAnmResult {
    u32 flag;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmTexImage;
    u32 prmTexPltt;
    fx32 scaleS;
    fx32 scaleT;
    fx16 rotSin;
    fx16 rotCos;
    fx32 transS;
    fx32 transT;
    u16 origWidth;
    u16 origHeight;
    fx32 magW;
    fx32 magH;
} NNSG3dMatAnmResult;
typedef struct NNSG3dJntAnmResult {
    u32 flag;
    VecFx32 scale;
    VecFx32 scaleEx0;
    VecFx32 scaleEx1;
    MtxFx33 rot;
    VecFx32 trans;
} NNSG3dJntAnmResult;
typedef struct NNSG3dVisAnmResult {
    BOOL isVisible;
} NNSG3dVisAnmResult;
typedef struct NNSG3dAnmObj NNSG3dAnmObj;
typedef BOOL (*UnkBlendFunc)(void *result, NNSG3dAnmObj *obj, u32 idx);
struct NNSG3dAnmObj {
    fx32 frame;
    fx32 ratio;
    void *resAnm;
    void *funcAnm;
    NNSG3dAnmObj *next;
    void *resTex;
    u8 priority;
    u8 numMapData;
    u16 mapData[1];
};
typedef struct NNSG3dRS NNSG3dRS;
typedef void (*UnkSbcCallback)(NNSG3dRS *rs);
typedef struct NNSG3dRenderObj {
    u32 flag;
    NNSG3dResMdl *resMdl;
    NNSG3dAnmObj *anmMat;
    UnkBlendFunc funcBlendMat;
    NNSG3dAnmObj *anmJnt;
    UnkBlendFunc funcBlendJnt;
    NNSG3dAnmObj *anmVis;
    UnkBlendFunc funcBlendVis;
    UnkSbcCallback cbFunc;
    u8 cbCmd;
    u8 cbTiming;
    u16 unk_26;
    UnkSbcCallback cbInitFunc;
    void *unk_2c;
    u8 *ptrUserSbc;
    NNSG3dJntAnmResult *recJntAnm;
    NNSG3dMatAnmResult *recMatAnm;
    u32 hintMatAnmExist[2];
    u32 hintJntAnmExist[2];
    u32 hintVisAnmExist[2];
} NNSG3dRenderObj;
typedef void (*UnkJntScaleFunc)(NNSG3dJntAnmResult *r, const void *p, const u8 *cmd, u32 flag);
typedef void (*UnkJntMtxFunc)(const NNSG3dJntAnmResult *r);
typedef void (*UnkTexMtxFunc)(NNSG3dMatAnmResult *r);
struct NNSG3dRS {
    u8 *c;
    NNSG3dRenderObj *pRenderObj;
    u32 flag;
    UnkSbcCallback cbVecFunc[32];
    u8 cbVecTiming[32];
    u8 currentNode;
    u8 currentMat;
    u8 currentNodeDesc;
    u8 unk_af;
    NNSG3dMatAnmResult *pMatAnmResult;
    NNSG3dJntAnmResult *pJntAnmResult;
    NNSG3dVisAnmResult *pVisAnmResult;
    u32 isMatCached[4];
    u32 isScaleCacheOne[2];
    NNSG3dResDict *pResNodeInfo;
    NNSG3dResMat *pResMat;
    NNSG3dResShp *pResShp;
    fx32 posScale;
    fx32 invPosScale;
    UnkJntScaleFunc funcJntScale;
    UnkJntMtxFunc funcJntMtx;
    UnkTexMtxFunc funcTexMtx;
    NNSG3dMatAnmResult tmpMatAnmResult;
    NNSG3dJntAnmResult tmpJntAnmResult;
    NNSG3dVisAnmResult tmpVisAnmResult;
};
typedef void (*UnkShpFunc)(NNSG3dRS *rs, u32 opt, const NNSG3dResShpData *shp, u32 idx);
static inline NNSG3dResShpData *GetShpDataByIdx(const NNSG3dResShp *shp, u32 idx) {
    const u32 *p = (const u32 *) GetResDataByIdx(&shp->dict, idx);
    return (NNSG3dResShpData *) ((u8 *) shp + *p);
}
extern UnkShpFunc data_021369c8[4];
void func_020f6cb0(NNSG3dRS *rs, u32 opt) {
    if (!(rs->flag & 0x200) && (rs->flag & 1) && !(rs->flag & 2)) {
        u32 shpID             = rs->c[1];
        NNSG3dResShpData *shp = GetShpDataByIdx(rs->pResShp, shpID);
        data_021369c8[shp->itemTag](rs, opt, shp, shpID);
    }
    rs->c += 2;
}
