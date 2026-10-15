/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02072b04 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/gfd/gfd_lnkvram.c (license: none),
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
extern BOOL func_020f32ac(UnkLnkVramMan *pMgr, UnkLnkVramBlock **ppBlockPool, u32 baseAddr, u32 szByte);
typedef struct {
    u32 start;
    u32 end;
} UnkLnkVramRegion;
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
BOOL func_020f32ac(UnkLnkVramMan *pMgr, UnkLnkVramBlock **ppBlockPool, u32 baseAddr, u32 szByte) {
    UnkLnkVramRegion region;
    UnkLnkVramRegion newRegion;
    UnkLnkVramRegion *pRegion = &region;
    UnkLnkVramBlock *pBlk;
    UnkLnkVramBlock *pNext;

    region.start = baseAddr;
    region.end   = baseAddr + szByte;
    newRegion    = region;

    pBlk = pMgr->pFreeList;
    while (pBlk != 0) {
        pNext = pBlk->pNext;
        if (pBlk->addr == pRegion->end) {
            newRegion.end = pBlk->addr + pBlk->szByte;
            RemoveBlock_(&pMgr->pFreeList, pBlk);
            InsertBlock_(ppBlockPool, pBlk);
        }
        if (pBlk->addr + pBlk->szByte == pRegion->start) {
            newRegion.start = pBlk->addr;
            RemoveBlock_(&pMgr->pFreeList, pBlk);
            InsertBlock_(ppBlockPool, pBlk);
        }
        pBlk = pNext;
    }

    pBlk = GetNewBlock_(ppBlockPool);
    if (pBlk == 0) {
        return 0;
    }
    InitBlock_(pBlk, newRegion.start, newRegion.end - newRegion.start);
    InsertBlock_(&pMgr->pFreeList, pBlk);
    return 1;
}
