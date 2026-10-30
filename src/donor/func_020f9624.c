/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020791f8 from projets/nintendogs-dachshund/src/donor/func_020791f8.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed short int s16;
typedef signed long s32;
typedef signed long long int s64;
typedef s32 fx32;
typedef s64 fx64;
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
typedef struct NNSG3dResJntAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u16 numNode;
    u32 flag;
    u32 ofsRot3;
    u32 ofsRot5;
} NNSG3dResJntAnm;
extern void func_020f9624(fx32 *s_invs, fx32 Frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void func_020f9624(fx32 *s_invs, fx32 Frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm) {
    u32 frame              = (u32) FX_Whole(Frame);
    const void *pArray     = (const void *) ((u8 *) pJntAnm + *(pData + 1));
    NNSG3dJntAnmSInfo info = (NNSG3dJntAnmSInfo) *pData;
    u32 last_interp;
    u32 idx;
    u32 idx_sub;

    ((void) 0);
    ((void) 0);

    if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK)) {
        idx = frame;
        goto SCALE_NONINTERP;
    }

    last_interp = ((u32) info & NNS_G3D_JNTANM_SINFO_LAST_INTERP_MASK) >> NNS_G3D_JNTANM_SINFO_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                idx = (last_interp >> 1) + 1;
                goto SCALE_NONINTERP;
            } else {
                idx = frame >> 1;
                goto SCALE_INTERP_2;
            }
        } else {
            idx = frame >> 1;
            goto SCALE_NONINTERP;
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                idx = (last_interp >> 2) + (frame & 3);
                goto SCALE_NONINTERP;
            }

            if (frame & 1) {
                fx32 v, v_sub;
                if (frame & 2) {
                    idx_sub = (frame >> 2);
                    idx     = idx_sub + 1;
                } else {
                    idx     = (frame >> 2);
                    idx_sub = idx + 1;
                }

                if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
                    const fx16 *p_fx16 = (const fx16 *) pArray;

                    v         = *(p_fx16 + 2 * idx);
                    v_sub     = *(p_fx16 + 2 * idx_sub);
                    s_invs[0] = (v + (v << 1) + v_sub) >> 2;

                    v         = *(p_fx16 + 2 * idx + 1);
                    v_sub     = *(p_fx16 + 2 * idx_sub + 1);
                    s_invs[1] = (v + (v << 1) + v_sub) >> 2;
                } else {
                    const fx32 *p_fx32 = (const fx32 *) pArray;

                    v     = *(p_fx32 + 2 * idx);
                    v_sub = *(p_fx32 + 2 * idx_sub);

                    s_invs[0] = (fx32) (((fx64) v + v + v + v_sub) >> 2);

                    v     = *(p_fx32 + 2 * idx + 1);
                    v_sub = *(p_fx32 + 2 * idx_sub + 1);

                    s_invs[1] = (fx32) (((fx64) v + v + v + v_sub) >> 2);
                }
                return;
            } else {
                idx = frame >> 2;
                goto SCALE_INTERP_2;
            }
        } else {
            idx = frame >> 2;
            goto SCALE_NONINTERP;
        }
    }
SCALE_NONINTERP:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
        const fx16 *p_fx16 = (const fx16 *) pArray;

        s_invs[0] = *(p_fx16 + 2 * idx);
        s_invs[1] = *(p_fx16 + 2 * idx + 1);
    } else {
        const fx32 *p_fx32 = (const fx32 *) pArray;

        s_invs[0] = *(p_fx32 + 2 * idx);
        s_invs[1] = *(p_fx32 + 2 * idx + 1);
    }
    return;
SCALE_INTERP_2:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
        const fx16 *p_fx16 = (const fx16 *) pArray;

        s_invs[0] = (*(p_fx16 + 2 * idx) + *(p_fx16 + 2 * idx + 2)) >> 1;
        s_invs[1] = (*(p_fx16 + 2 * idx + 1) + *(p_fx16 + 2 * idx + 3)) >> 1;
    } else {
        const fx32 *p_fx32 = (const fx32 *) pArray;

        s_invs[0] = (*(p_fx32 + 2 * idx) + (*(p_fx32 + 2 * idx + 2))) >> 1;
        s_invs[1] = (*(p_fx32 + 2 * idx + 1) + (*(p_fx32 + 2 * idx + 3))) >> 1;
    }
    return;
}
