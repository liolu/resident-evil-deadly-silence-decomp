/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206eccc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_anm_jnt.c (license: none),
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
extern NNSG3dRS *data_02154608;
typedef struct UnkResJntAnm {
    u8 anmHeader[4];
    u16 numFrame;
    u16 numNode;
    u32 flag;
    u32 ofsRot3;
    u32 ofsRot9;
    u16 ofsTag[1];
} UnkResJntAnm;
extern void func_020f9b5c(const UnkResJntAnm *res, u32 idx, fx32 frame, NNSG3dJntAnmResult *r);
extern void func_020f99d0(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
extern void func_020f9854(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
extern void func_020f9624(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
extern void func_020f946c(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
extern void func_020f9064(MtxFx33 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
extern void func_020f8d18(MtxFx33 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
extern BOOL func_020f8b78(MtxFx33 *out, const void *rot3, const void *rot9, u32 info);
void func_020fa10c(NNSG3dJntAnmResult *r);
void func_020fa0a4(NNSG3dJntAnmResult *r);
void func_020f9f44(NNSG3dJntAnmResult *r);
void func_020f9b5c(const UnkResJntAnm *res, u32 idx, fx32 frame, NNSG3dJntAnmResult *r) {
    const u32 *tag = (const u32 *) ((u8 *) res + res->ofsTag[idx]);
    u32 flag       = *tag;
    BOOL interp;
    const u32 *p;
    struct {
        VecFx32 s;
        VecFx32 inv;
    } scale;

    if (flag & 1) {
        r->flag = 7;
    } else {
        p       = tag + 1;
        interp  = ((frame & 0xfff) && (res->flag & 1)) ? 1 : 0;
        r->flag = 0;

        if (!(flag & 6)) {
            if (!(flag & 8)) {
                if (interp) {
                    func_020f9854(&r->trans.x, frame, p, res);
                } else {
                    func_020f99d0(&r->trans.x, frame, p, res);
                }
                p += 2;
            } else {
                r->trans.x = (fx32) *p++;
            }

            if (!(flag & 0x10)) {
                if (interp) {
                    func_020f9854(&r->trans.y, frame, p, res);
                } else {
                    func_020f99d0(&r->trans.y, frame, p, res);
                }
                p += 2;
            } else {
                r->trans.y = (fx32) *p++;
            }

            if (!(flag & 0x20)) {
                if (interp) {
                    func_020f9854(&r->trans.z, frame, p, res);
                } else {
                    func_020f99d0(&r->trans.z, frame, p, res);
                }
                p += 2;
            } else {
                r->trans.z = (fx32) *p++;
            }
        } else if (flag & 2) {
            r->flag |= 4;
        } else {
            func_020fa10c(r);
        }

        if (!(flag & 0xc0)) {
            if (!(flag & 0x100)) {
                if (interp) {
                    func_020f8d18(&r->rot, frame, p, res);
                } else {
                    func_020f9064(&r->rot, frame, p, res);
                }
                p += 2;
            } else {
                if (func_020f8b78(&r->rot, (u8 *) res + res->ofsRot3, (u8 *) res + res->ofsRot9, *p)) {
                    fx32 x     = (r->rot._01 * r->rot._12 - r->rot._02 * r->rot._11) >> 12;
                    fx32 y     = (r->rot._02 * r->rot._10 - r->rot._00 * r->rot._12) >> 12;
                    fx32 z     = (r->rot._00 * r->rot._11 - r->rot._01 * r->rot._10) >> 12;
                    r->rot._20 = x;
                    r->rot._21 = y;
                    r->rot._22 = z;
                }
                p++;
            }
        } else if (flag & 0x40) {
            r->flag |= 2;
        } else {
            func_020f9f44(r);
        }

        if (!(flag & 0x600)) {
            if (!(flag & 0x800)) {
                fx32 tmp[2];
                if (interp) {
                    func_020f946c(tmp, frame, p, res);
                } else {
                    func_020f9624(tmp, frame, p, res);
                }
                scale.s.x   = tmp[0];
                scale.inv.x = tmp[1];
            } else {
                scale.s.x   = p[0];
                scale.inv.x = p[1];
            }

            if (!(flag & 0x1000)) {
                fx32 tmp[2];
                if (interp) {
                    func_020f946c(tmp, frame, p + 2, res);
                } else {
                    func_020f9624(tmp, frame, p + 2, res);
                }
                scale.s.y   = tmp[0];
                scale.inv.y = tmp[1];
            } else {
                scale.s.y   = p[2];
                scale.inv.y = p[3];
            }

            if (!(flag & 0x2000)) {
                fx32 tmp[2];
                if (interp) {
                    func_020f946c(tmp, frame, p + 4, res);
                } else {
                    func_020f9624(tmp, frame, p + 4, res);
                }
                scale.s.z   = tmp[0];
                scale.inv.z = tmp[1];
            } else {
                scale.s.z   = p[4];
                scale.inv.z = p[5];
            }
        } else if (flag & 0x200) {
            r->flag |= 1;
        } else {
            func_020fa0a4(r);
            return;
        }
    }

    data_02154608->funcJntScale(r, &scale, data_02154608->c, (r->flag & 1) ? 4 : 0);
}
void func_020f99d0(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
void func_020f9854(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
void func_020f9624(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
void func_020f946c(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
