/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02079040 from projets/nintendogs-dachshund/src/donor/func_02079040.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed short int s16;
typedef signed long s32;
typedef s32 fx32;
typedef s16 fx16;
extern s32 FX_Whole(fx32 v);
static inline s32 FX_Whole(fx32 v) {
    return (s32) (v >> 12);
}
extern const u16(*ctrdgi_fl_maxtime);
typedef struct NNSG3dResAnmHeader_ {
    u8 category0;
    u8 revision;
    u16 category1;
} NNSG3dResAnmHeader;
typedef enum {
    NNS_G3D_JNTANM_SINFO_STEP_1            = 0x00000000,
    NNS_G3D_JNTANM_SINFO_STEP_2            = 0x40000000,
    NNS_G3D_JNTANM_SINFO_STEP_4            = 0x80000000,
    NNS_G3D_JNTANM_SINFO_FX16ARRAY         = 0x20000000,
    NNS_G3D_JNTANM_SINFO_LAST_INTERP_MASK  = 0x1fff0000,
    NNS_G3D_JNTANM_SINFO_STEP_MASK         = 0xc0000000,
    NNS_G3D_JNTANM_SINFO_LAST_INTERP_SHIFT = 16,
    NNS_G3D_JNTANM_SINFO_STEP_SHIFT        = 30
} NNSG3dJntAnmSInfo;
typedef enum {
    NNS_G3D_JNTANM_OPTION_INTERPOLATION              = 0x01,
    NNS_G3D_JNTANM_OPTION_END_TO_START_INTERPOLATION = 0x02
} NNSG3dJntAnmOption;
typedef struct NNSG3dResJntAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u16 numNode;
    u32 flag;
    u32 ofsRot3;
    u32 ofsRot5;
} NNSG3dResJntAnm;
extern void func_020f946c(fx32 *s_invs, fx32 Frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void func_020f946c(fx32 *s_invs, fx32 Frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm) {
    const void *pArray     = (const void *) ((const u8 *) pJntAnm + *(pData + 1));
    NNSG3dJntAnmSInfo info = (NNSG3dJntAnmSInfo) *pData;
    u32 last_interp;
    u32 idx0, idx1;
    fx32 remainder;
    int step;
    u32 step_shift;
    u32 frame;

    frame = (u32) FX_Whole(Frame);

    if (frame == pJntAnm->numFrame - 1) {
        if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK)) {
            idx0 = frame;
        } else if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
            idx0 = (frame >> 1) + (frame & 1);
        } else {
            idx0 = (frame >> 2) + (frame & 3);
        }

        if (pJntAnm->flag & NNS_G3D_JNTANM_OPTION_END_TO_START_INTERPOLATION) {
            idx1 = 0;
            goto SCALE_EX_0_1;
        } else {
            if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
                const fx16 *p_fx16 = (const fx16 *) pArray;

                s_invs[0] = *(p_fx16 + 2 * idx0);
                s_invs[1] = *(p_fx16 + 2 * idx0 + 1);
            } else {
                const fx32 *p_fx32 = (const fx32 *) pArray;

                s_invs[0] = *(p_fx32 + 2 * idx0);
                s_invs[1] = *(p_fx32 + 2 * idx0 + 1);
            }
            return;
        }
    }

    if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK)) {
        goto SCALE_EX_0;
    }

    last_interp = ((u32) info & NNS_G3D_JNTANM_SINFO_LAST_INTERP_MASK) >> NNS_G3D_JNTANM_SINFO_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {

        if (frame >= last_interp) {
            idx0 = (last_interp >> 1);
            idx1 = idx0 + 1;
            goto SCALE_EX_0_1;
        } else {
            idx0       = frame >> 1;
            idx1       = idx0 + 1;
            remainder  = Frame & (((fx32) 0x0000000000001000L) * 2 - 1);
            step       = 2;
            step_shift = 1;
            goto SCALE_EX;
        }
    } else {
        if (frame >= last_interp) {
            idx0 = (frame >> 2) + (frame & 3);
            idx1 = idx0 + 1;
            goto SCALE_EX_0_1;
        } else {
            idx0       = frame >> 2;
            idx1       = idx0 + 1;
            remainder  = Frame & (((fx32) 0x0000000000001000L) * 4 - 1);
            step       = 4;
            step_shift = 2;
            goto SCALE_EX;
        }
    }
    ((void) 0);
SCALE_EX_0:
    idx0 = (u32) frame;
    idx1 = idx0 + 1;
SCALE_EX_0_1:
    remainder  = Frame & (((fx32) 0x0000000000001000L) - 1);
    step       = 1;
    step_shift = 0;
SCALE_EX: {
    fx32 s0, s1;
    fx32 inv0, inv1;

    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
        const fx16 *p_fx16 = (const fx16 *) pArray;

        s0   = *(p_fx16 + 2 * idx0);
        inv0 = *(p_fx16 + 2 * idx0 + 1);

        s1   = *(p_fx16 + 2 * idx1);
        inv1 = *(p_fx16 + 2 * idx1 + 1);
    } else {
        const fx32 *p_fx32 = (const fx32 *) pArray;

        s0   = *(p_fx32 + 2 * idx0);
        inv0 = *(p_fx32 + 2 * idx0 + 1);

        s1   = *(p_fx32 + 2 * idx1);
        inv1 = *(p_fx32 + 2 * idx1 + 1);
    }

    s_invs[0] = ((s0 * step) + (((s1 - s0) * remainder) >> 12)) >> step_shift;
    s_invs[1] = ((inv0 * step) + (((inv1 - inv0) * remainder) >> 12)) >> step_shift;
}

    return;
}
