/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02015aa0 from https://github.com/RonyxDumb/mkds src/arm9/02015aa0_func_02015aa0.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed short int s16;
typedef signed long s32;
typedef s32 fx32;
typedef s16 fx16;
extern const u16(*ctrdgi_fl_maxtime);
typedef struct NNSG3dResDictTreeNode_ {
    u8 refBit;
    u8 idxLeft;
    u8 idxRight;
    u8 idxEntry;
} NNSG3dResDictTreeNode;
typedef struct NNSG3dResDict_ {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
    NNSG3dResDictTreeNode node[1];
} NNSG3dResDict;
typedef struct NNSG3dResAnmHeader_ {
    u8 category0;
    u8 revision;
    u16 category1;
} NNSG3dResAnmHeader;
typedef enum {
    NNS_G3D_TEXSRTANM_ELEM_FX16              = 0x10000000,
    NNS_G3D_TEXSRTANM_ELEM_CONST             = 0x20000000,
    NNS_G3D_TEXSRTANM_ELEM_STEP_1            = 0x00000000,
    NNS_G3D_TEXSRTANM_ELEM_STEP_2            = 0x40000000,
    NNS_G3D_TEXSRTANM_ELEM_STEP_4            = 0x80000000,
    NNS_G3D_TEXSRTANM_ELEM_STEP_MASK         = 0xc0000000,
    NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_MASK  = 0x0000ffff,
    NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_SHIFT = 0
} NNSG3dTexSRTElem;
typedef struct NNSG3dResTexSRTAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u8 flag;
    u8 texMtxMode;
    NNSG3dResDict dict;
} NNSG3dResTexSRTAnm;
#pragma thumb off
fx32 func_020fa9a0(const NNSG3dResTexSRTAnm *pTexAnm, u32 info, u32 data, u32 frame) {
    u32 idx, idx_sub;
    u32 last_interp;
    const void *pDataHead;

    if (info & NNS_G3D_TEXSRTANM_ELEM_CONST) {
        return (fx32) data;
    }

    pDataHead = (const void *) ((u8 *) pTexAnm + data);

    if (!(info & NNS_G3D_TEXSRTANM_ELEM_STEP_MASK)) {
        idx = frame;
        goto TEXSRT_VAL_NONINTERP;
    }

    last_interp = (NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_MASK & info) >> NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_TEXSRTANM_ELEM_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                idx = (last_interp >> 1) + 1;
                goto TEXSRT_VAL_NONINTERP;
            } else {
                idx = frame >> 1;
                goto TEXSRT_VAL_INTERP_2;
            }
        } else {
            idx = frame >> 1;
            goto TEXSRT_VAL_NONINTERP;
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                idx = (last_interp >> 2) + (frame & 3);
                goto TEXSRT_VAL_NONINTERP;
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

                if (info & NNS_G3D_TEXSRTANM_ELEM_FX16) {
                    v     = *((const fx16 *) pDataHead + idx);
                    v_sub = *((const fx16 *) pDataHead + idx_sub);
                } else {
                    v     = *((const fx32 *) pDataHead + idx);
                    v_sub = *((const fx32 *) pDataHead + idx_sub);
                }
                return (v + v + v + v_sub) >> 2;
            } else {
                idx = frame >> 2;
                goto TEXSRT_VAL_INTERP_2;
            }
        } else {
            idx = frame >> 2;
            goto TEXSRT_VAL_NONINTERP;
        }
    }
    ((void) 0);
TEXSRT_VAL_NONINTERP:
    if (info & NNS_G3D_TEXSRTANM_ELEM_FX16) {
        return *((const fx16 *) pDataHead + idx);
    } else {
        return *((const fx32 *) pDataHead + idx);
    }
TEXSRT_VAL_INTERP_2: {
    fx32 v0, v1;
    if (info & NNS_G3D_TEXSRTANM_ELEM_FX16) {
        v0 = *((const fx16 *) pDataHead + idx);
        v1 = *((const fx16 *) pDataHead + idx + 1);
    } else {
        v0 = *((const fx32 *) pDataHead + idx);
        v1 = *((const fx32 *) pDataHead + idx + 1);
    }
    return ((v0 + v1) >> 1);
}
}
