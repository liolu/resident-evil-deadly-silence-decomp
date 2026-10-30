/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020154e4 from https://github.com/RonyxDumb/mkds src/arm9/020154e4_func_020154e4.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
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
    NNS_G3D_MATCANM_ELEM_CONST                 = 0x20000000,
    NNS_G3D_MATCANM_ELEM_STEP_1                = 0x00000000,
    NNS_G3D_MATCANM_ELEM_STEP_2                = 0x40000000,
    NNS_G3D_MATCANM_ELEM_STEP_4                = 0x80000000,
    NNS_G3D_MATCANM_ELEM_STEP_MASK             = 0xc0000000,
    NNS_G3D_MATCANM_ELEM_LAST_INTERP_MASK      = 0x1fff0000,
    NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_MASK  = 0x0000ffff,
    NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_SHIFT = 0,
    NNS_G3D_MATCANM_ELEM_LAST_INTERP_SHIFT     = 16
} NNSG3dMatCElem;
typedef struct NNSG3dResMatCAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u16 flag;
    NNSG3dResDict dict;
} NNSG3dResMatCAnm;
#pragma thumb off
u16 func_020fa3e4(const NNSG3dResMatCAnm *pAnm, u32 info, u32 frame) {
    const u8 *pDataHead;
    u32 last_interp;

    if (info & NNS_G3D_MATCANM_ELEM_CONST) {
        return (u16) (info & NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_MASK);
    }

    pDataHead = (const u8 *) pAnm + (info & NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_MASK);

    if (!(info & NNS_G3D_MATCANM_ELEM_STEP_MASK)) {
        return *(pDataHead + frame);
    }

    last_interp = (NNS_G3D_MATCANM_ELEM_LAST_INTERP_MASK & info) >> NNS_G3D_MATCANM_ELEM_LAST_INTERP_SHIFT;
    if (info & NNS_G3D_MATCANM_ELEM_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                return *(pDataHead + (last_interp >> 1) + 1);
            } else {
                return (u16) ((*(pDataHead + (frame >> 1)) + *(pDataHead + (frame >> 1) + 1)) >> 1);
            }
        } else {
            return *(pDataHead + (frame >> 1));
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                return *(pDataHead + (last_interp >> 2) + (frame & 3));
            }

            if (frame & 1) {
                u32 idx, idx_sub;
                u32 v, v_sub;

                if (frame & 2) {
                    idx_sub = (frame >> 2);
                    idx     = idx_sub + 1;
                } else {
                    idx     = (frame >> 2);
                    idx_sub = idx + 1;
                }

                v     = *(pDataHead + idx);
                v_sub = *(pDataHead + idx_sub);

                return (u16) ((v + v + v + v_sub) >> 2);
            } else {
                return (u16) ((*(pDataHead + (frame >> 2)) + *(pDataHead + (frame >> 2) + 1)) >> 1);
            }
        } else {
            return *(pDataHead + (frame >> 2));
        }
    }
    ((void) 0);
}
