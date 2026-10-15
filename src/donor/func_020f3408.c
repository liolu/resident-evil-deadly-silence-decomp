/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020729c4 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/gfd/gfd_lnkvram.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef int s32;
typedef s32 BOOL;
typedef struct UnkLnkVramBlock {
    u32 addr;
    u32 szByte;
    struct UnkLnkVramBlock *pPrev;
    struct UnkLnkVramBlock *pNext;
} UnkLnkVramBlock;
typedef struct {
    UnkLnkVramBlock *pFreeList;
} UnkLnkVramMan;
extern BOOL func_020f3408(UnkLnkVramMan *pMgr, UnkLnkVramBlock **ppBlockPool, u32 *pRetAddr, u32 szByte, u32 alignment);
static inline UnkLnkVramBlock *GetNewBlock_(UnkLnkVramBlock **ppBlockPool) {
    UnkLnkVramBlock *pBlk = *ppBlockPool;
    if (pBlk != 0) {
        *ppBlockPool = pBlk->pNext;
    }
    return pBlk;
}
static inline void InitBlock_(UnkLnkVramBlock *pBlk, u32 addr, u32 szByte) {
    pBlk->addr   = addr;
    pBlk->szByte = szByte;
    pBlk->pPrev  = 0;
    pBlk->pNext  = 0;
}
static inline void InsertBlock_(UnkLnkVramBlock **ppList, UnkLnkVramBlock *pBlk) {
    if (*ppList != 0) {
        (*ppList)->pPrev = pBlk;
    }
    pBlk->pNext = *ppList;
    pBlk->pPrev = 0;
    *ppList     = pBlk;
}
static inline void RemoveBlock_(UnkLnkVramBlock **ppList, UnkLnkVramBlock *pBlk) {
    UnkLnkVramBlock *pPrev = pBlk->pPrev;
    UnkLnkVramBlock *pNext = pBlk->pNext;

    if (pPrev != 0) {
        pPrev->pNext = pNext;
    } else {
        *ppList = pNext;
    }
    if (pNext != 0) {
        pNext->pPrev = pPrev;
    }
}
BOOL func_020f3408(UnkLnkVramMan *pMgr, UnkLnkVramBlock **ppBlockPool, u32 *pRetAddr, u32 szByte, u32 alignment) {
    u32 alignedAddr;
    u32 needSize;
    u32 alignOfs;
    UnkLnkVramBlock *pFound = 0;
    UnkLnkVramBlock *pBlk   = pMgr->pFreeList;

    while (pBlk != 0) {
        if (alignment > 1) {
            alignedAddr = (pBlk->addr + (alignment - 1)) & ~(alignment - 1);
            alignOfs    = alignedAddr - pBlk->addr;
            needSize    = szByte + alignOfs;
        } else {
            alignedAddr = pBlk->addr;
            alignOfs    = 0;
            needSize    = szByte;
        }
        if (pBlk->szByte >= needSize) {
            pFound = pBlk;
            break;
        }
        pBlk = pBlk->pNext;
    }

    if (pFound != 0) {
        if (alignOfs != 0) {
            UnkLnkVramBlock *pNew = GetNewBlock_(ppBlockPool);
            if (pNew == 0) {
                goto fail;
            }
            InitBlock_(pNew, pFound->addr, alignOfs);
            InsertBlock_(&pMgr->pFreeList, pNew);
        }
        pFound->szByte -= needSize;
        pFound->addr += needSize;
        if (pFound->szByte == 0) {
            RemoveBlock_(&pMgr->pFreeList, pFound);
            InsertBlock_(ppBlockPool, pFound);
        }
        *pRetAddr = alignedAddr;
        return 1;
    }
fail:
    *pRetAddr = 0;
    return 0;
}
