/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* NNSi_G3dGetTexPatAnmFV from https://github.com/Yokimitsuro/khdays-decomp libs/nns/g3d/calls/NNSi_G3dGetTexPatAnmFV.c
 * (license: CC0-1.0), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef short s16;
typedef signed long s32;
typedef s16 fx16;
typedef s32 fx32;
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
typedef struct NNSG3dResDictTexPatAnmData_ {
    u16 numFV;
    u16 flag;
    fx16 ratioDataFrame;
    u16 offset;
} NNSG3dResDictTexPatAnmData;
typedef struct NNSG3dResTexPatAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u8 numTex;
    u8 numPltt;
    u16 ofsTexName;
    u16 ofsPlttName;
    NNSG3dResDict dict;
} NNSG3dResTexPatAnm;
typedef struct NNSG3dResTexPatAnmFV_ {
    u16 idxFrame;
    u8 idTex;
    u8 idPltt;
} NNSG3dResTexPatAnmFV;
extern const NNSG3dResDictTexPatAnmData *func_020f8a84(const NNSG3dResTexPatAnm *pPatAnm, u32 idx);
extern const NNSG3dResDictTexPatAnmData *func_020f8a84(const NNSG3dResTexPatAnm *pPatAnm, u32 idx);
const NNSG3dResTexPatAnmFV *func_020f8aa0(const NNSG3dResTexPatAnm *pPatAnm, u32 idx, u32 frame) {
    {
        const NNSG3dResDictTexPatAnmData *pAnmData = func_020f8a84(pPatAnm, idx);
        {

            const NNSG3dResTexPatAnmFV *pfvArray = (const NNSG3dResTexPatAnmFV *) ((u8 *) pPatAnm + pAnmData->offset);

            const u32 fvIdx = (u32) ((fx32) pAnmData->ratioDataFrame * frame >> 12);

            {
                u32 realFvIdx = fvIdx;

                while (realFvIdx > 0 && pfvArray[realFvIdx].idxFrame >= frame) {
                    realFvIdx--;
                }

                while (realFvIdx + 1 < pAnmData->numFV && pfvArray[realFvIdx + 1].idxFrame <= frame) {
                    realFvIdx++;
                }

                return &pfvArray[realFvIdx];
            }
        }
    }
}
