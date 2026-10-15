/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02072908 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/gfd/gfd_lnkvram.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef struct UnkLnkVramBlock {
    u32 addr;
    u32 szByte;
    struct UnkLnkVramBlock *pPrev;
    struct UnkLnkVramBlock *pNext;
} UnkLnkVramBlock;
extern UnkLnkVramBlock *func_020f35e0(UnkLnkVramBlock *pArray, u32 num);
UnkLnkVramBlock *func_020f35e0(UnkLnkVramBlock *pArray, u32 num) {
    u32 i;

    for (i = 0; i < num - 1; i++) {
        pArray[i].pNext     = &pArray[i + 1];
        pArray[i + 1].pPrev = &pArray[i];
    }
    pArray[0].pPrev           = 0;
    (pArray + num - 1)->pNext = 0;
    return pArray;
}
