/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207b2cc from projets/nintendogs-dachshund/src/donor/func_0207b2cc.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed short int s16;
typedef signed long s32;
typedef signed long long int s64;
typedef s32 fx32;
typedef s64 fx64;
typedef s16 fx16;
typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
        fx32 _30, _31, _32;
    };
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;
typedef enum {
    GX_MTXMODE_PROJECTION      = 0,
    GX_MTXMODE_POSITION        = 1,
    GX_MTXMODE_POSITION_VECTOR = 2,
    GX_MTXMODE_TEXTURE         = 3
} GXMtxMode;
extern const u16(*ctrdgi_fl_maxtime);
typedef enum {
    NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE  = 0x00000001,
    NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO   = 0x00000002,
    NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO = 0x00000004,
    NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET       = 0x00000008,
    NNS_G3D_MATANM_RESULTFLAG_TEXMTX_MULT      = 0x00000010,
    NNS_G3D_MATANM_RESULTFLAG_WIREFRAME        = 0x00000020
} NNSG3dMatAnmResultFlag;
typedef struct NNSG3dMatAnmResult_ {
    NNSG3dMatAnmResultFlag flag;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmTexImage;
    u32 prmTexPltt;
    fx32 scaleS, scaleT;
    fx16 sinR, cosR;
    fx32 transS, transT;
    u16 origWidth, origHeight;
    fx32 magW, magH;
} NNSG3dMatAnmResult;
extern void func_020fb6c8(const NNSG3dMatAnmResult *anm);
extern inline void NNS_G3dGeBufferData_N(const u32 *args, u32 num);
extern void func_020f7b18(u32 op, const u32 *args, u32 num);
inline void NNS_G3dGeBufferData_N(const u32 *args, u32 num) {
    ((void) 0);
    func_020f7b18(*args, args + 1, num - 1);
}
void func_020fb6c8(const NNSG3dMatAnmResult *anm) {
    struct {
        u32 cmd;
        u32 mode_tex;
        MtxFx43 m;
        u32 mode_pos_vec;
    } data;

    ((void) 0);
    ((void) 0);

    if (anm->flag & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET) {
        data.cmd = ((u32) ((0x10) | ((0x17) << 8) | ((0x10) << 16) | ((0x00) << 24)));
    } else {
        data.cmd = ((u32) ((0x10) | ((0x19) << 8) | ((0x10) << 16) | ((0x00) << 24)));
    }

    data.mode_tex     = GX_MTXMODE_TEXTURE;
    data.mode_pos_vec = GX_MTXMODE_POSITION_VECTOR;

    data.m._01 = data.m._02 = data.m._10 = data.m._12 = data.m._20 = data.m._21 = data.m._22 = data.m._32 = 0;

    if (anm->flag & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO) {
        data.m._30 = 0;
        data.m._31 = 0;

        if (anm->flag & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE) {
            data.m._00 = ((fx32) 0x0000000000001000L);
            data.m._11 = ((fx32) 0x0000000000001000L);
        } else {
            data.m._00 = anm->scaleS;
            data.m._11 = anm->scaleT;
        }
    } else if (anm->flag & NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE) {
        data.m._30 = -(anm->transS << 4) * anm->origWidth;
        data.m._31 = -(anm->transT << 4) * anm->origHeight;
        data.m._00 = ((fx32) 0x0000000000001000L);
        data.m._11 = ((fx32) 0x0000000000001000L);
    } else {
        data.m._30 = -(fx32) ((fx64) anm->scaleS * anm->transS >> (12 - 4)) * anm->origWidth;
        data.m._31 = -(fx32) ((fx64) anm->scaleT * anm->transT >> (12 - 4)) * anm->origHeight;
        data.m._00 = anm->scaleS;
        data.m._11 = anm->scaleT;
    }

    if (anm->magW != ((fx32) 0x0000000000001000L)) {
        data.m._00 = (fx32) ((fx64) anm->magW * data.m._00 >> 12);
        data.m._30 = (fx32) ((fx64) anm->magW * data.m._30 >> 12);
    }

    if (anm->magH != ((fx32) 0x0000000000001000L)) {
        data.m._11 = (fx32) ((fx64) anm->magH * data.m._11 >> 12);
        data.m._31 = (fx32) ((fx64) anm->magH * data.m._31 >> 12);
    }

    NNS_G3dGeBufferData_N((u32 *) &data.cmd, sizeof(data) / 4);
}
