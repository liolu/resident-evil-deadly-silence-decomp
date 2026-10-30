/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020753c4 from projets/nintendogs-dachshund/src/donor/func_020753c4.c (same code in another game of this workspace),
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
typedef struct {
    fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22, _30, _31, _32;
} MtxFx43;
typedef struct {
    fx32 _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33;
} MtxFx44;
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
typedef struct NNSG3dResShp {
    NNSG3dResDict dict;
} NNSG3dResShp;
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
typedef struct NNSG3dGlb {
    u32 unk_000[2];
    MtxFx44 projMtx;
    u32 unk_048;
    MtxFx43 cameraMtx;
    u8 unk_07c[0x94 - 0x7c];
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u8 unk_0a0[0xbc - 0xa0];
    MtxFx33 prmBaseRot;
    VecFx32 unk_0e0;
    u8 unk_0ec[0xfc - 0xec];
    u32 flag;
} NNSG3dGlb;
static inline NNSG3dResMatData *GetMatDataByIdx(const NNSG3dResMat *mat, u32 idx) {
    const u32 *p = (const u32 *) GetResDataByIdx(&mat->dict, idx);
    return (NNSG3dResMatData *) ((u8 *) mat + *p);
}
static inline u32 CheckCallBack(NNSG3dRS *rs, u32 cmd) {
    return rs->cbVecFunc[cmd] ? rs->cbVecTiming[cmd] : 0;
}
static inline BOOL CallBackCheck_A(NNSG3dRS *rs, u32 cmd, u32 *pTiming) {
    *pTiming = CheckCallBack(rs, cmd);
    if (*pTiming == 1) {
        rs->flag &= ~0x40;
        rs->cbVecFunc[cmd](rs);
        *pTiming = CheckCallBack(rs, cmd);
        return rs->flag & 0x40;
    }
    return 0;
}
static inline BOOL CallBackCheck_B(NNSG3dRS *rs, u32 cmd, u32 *pTiming) {
    if (*pTiming == 2) {
        rs->flag &= ~0x40;
        rs->cbVecFunc[cmd](rs);
        *pTiming = CheckCallBack(rs, cmd);
        return rs->flag & 0x40;
    }
    return 0;
}
static inline BOOL CallBackCheck_C(NNSG3dRS *rs, u32 cmd, u32 timing) {
    if (timing == 3) {
        rs->flag &= ~0x40;
        rs->cbVecFunc[cmd](rs);
        return rs->flag & 0x40;
    }
    return 0;
}
extern void func_020f7b18(u32 op, const void *args, u32 num);
extern void func_020f81f8(MtxFx43 *m, MtxFx33 *n);
extern NNSG3dGlb data_021543a4;
extern u32 data_021369b0[2];
void func_020f56b0(NNSG3dRS *rs, u32 opt) {
    if (!(rs->flag & 0x200) && (rs->flag & 1)) {
        u32 timing;
        BOOL cbFlag;
        MtxFx33 m;
        VecFx32 s;

        if ((rs->pMatAnmResult->prmTexImage & 0xc0000000) != 0x80000000) {
            rs->pMatAnmResult->prmTexImage &= ~0xc0000000;
            rs->pMatAnmResult->prmTexImage |= 0x80000000;
            data_021369b0[1] = rs->pMatAnmResult->prmTexImage;
            func_020f7b18(data_021369b0[0], &data_021369b0[1], 1);
        }

        {
            u32 arg = 3;
            func_020f7b18(0x10, &arg, 1);
        }

        cbFlag = CallBackCheck_A(rs, 0xc, &timing);
        if (!cbFlag) {
            fx32 w, h;
            u32 arg;

            h   = rs->pMatAnmResult->origHeight;
            w   = rs->pMatAnmResult->origWidth;
            s.x = w << 15;
            s.y = -h << 15;
            s.z = 0x10000;
            func_020f7b18(0x1b, &s, 3);
            arg = (u16) (fx16) (w << 3) | ((u16) (fx16) (h << 3) << 16);
            func_020f7b18(0x22, &arg, 1);
        }

        cbFlag = CallBackCheck_B(rs, 0xc, &timing);
        if (!cbFlag) {
            NNSG3dResMatData *mat = GetMatDataByIdx(rs->pResMat, rs->c[1]);
            if (mat->flag & 0x2000) {
                const u8 *p = mat->texMtx;
                if (!(mat->flag & 2)) {
                    p += 8;
                }
                if (!(mat->flag & 4)) {
                    p += 4;
                }
                if (!(mat->flag & 8)) {
                    p += 8;
                }
                func_020f7b18(0x18, p, 0x10);
            }
        }

        cbFlag = CallBackCheck_C(rs, 0xc, timing);
        if (!cbFlag) {
            u32 arg2 = 2;
            u32 arg3;

            func_020f7b18(0x10, &arg2, 1);
            func_020f81f8(0, &m);
            arg3 = 3;
            func_020f7b18(0x10, &arg3, 1);

            if (data_021543a4.flag & 1) {
                func_020f7b18(0x1a, &data_021543a4.cameraMtx, 9);
                func_020f7b18(0x1a, &data_021543a4.prmBaseRot, 9);
                func_020f7b18(0x1a, &m, 9);
            } else if (data_021543a4.flag & 2) {
                func_020f7b18(0x1a, &data_021543a4.cameraMtx, 9);
                func_020f7b18(0x1a, &m, 9);
            } else {
                func_020f7b18(0x1a, &m, 9);
            }
        }

        {
            u32 arg = 2;
            func_020f7b18(0x10, &arg, 1);
        }
    }
    rs->c += 3;
}
