/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* AllocFromHead from https://github.com/RonyxDumb/mkds src/arm9/020176c0_Mem_Exp_GetAllocatableSize.c (license: none), reused
 * by tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef int BOOL;
extern const u16(*ctrdgi_fl_maxtime);
typedef struct {
    void *prevObject;
    void *nextObject;
} NNSFndLink;
typedef struct {
    void *headObject;
    void *tailObject;
    u16 numObjects;
    u16 offset;
} NNSFndList;
typedef struct NNSiFndHeapHead NNSiFndHeapHead;
struct NNSiFndHeapHead {
    u32 signature;
    NNSFndLink link;
    NNSFndList childList;
    void *heapStart;
    void *heapEnd;
    u32 attribute;
};
enum {
    NNS_FND_EXPHEAP_ALLOC_DIR_FRONT,
    NNS_FND_EXPHEAP_ALLOC_DIR_REAR
};
enum {
    NNS_FND_EXPHEAP_ALLOC_MODE_FIRST,
    NNS_FND_EXPHEAP_ALLOC_MODE_NEAR
};
typedef struct NNSiFndExpHeapMBlockHead NNSiFndExpHeapMBlockHead;
struct NNSiFndExpHeapMBlockHead {
    u16 signature;
    u16 attribute;
    u32 blockSize;
    NNSiFndExpHeapMBlockHead *pMBHeadPrev;
    NNSiFndExpHeapMBlockHead *pMBHeadNext;
};
typedef struct NNSiFndExpMBlockList NNSiFndExpMBlockList;
struct NNSiFndExpMBlockList {
    NNSiFndExpHeapMBlockHead *head;
    NNSiFndExpHeapMBlockHead *tail;
};
typedef struct NNSiFndExpHeapHead NNSiFndExpHeapHead;
struct NNSiFndExpHeapHead {
    NNSiFndExpMBlockList mbFreeList;
    NNSiFndExpMBlockList mbUsedList;
    u16 groupID;
    u16 feature;
};
typedef u32 NNSiUIntPtr;
inline NNSiUIntPtr NNSiGetUIntPtr(const void *ptr) {
    return (NNSiUIntPtr) ptr;
}
inline u32 GetOffsetFromPtr(const void *start, const void *end) {
    return NNSiGetUIntPtr(end) - NNSiGetUIntPtr(start);
}
inline void *AddU32ToPtr(void *ptr, u32 val) {
    return (void *) (NNSiGetUIntPtr(ptr) + val);
}
static inline NNSiFndExpHeapHead *GetExpHeapHeadPtrFromHeapHead(NNSiFndHeapHead *pHHead) {
    return AddU32ToPtr(pHHead, sizeof(NNSiFndHeapHead));
}
static inline void *GetMemPtrForMBlock(NNSiFndExpHeapMBlockHead *pMBlkHd) {
    return AddU32ToPtr(pMBlkHd, sizeof(NNSiFndExpHeapMBlockHead));
}
static inline u16 GetAllocMode(NNSiFndExpHeapHead *pEHHead) {
    return (u16) (((pEHHead->feature) >> (0)) & ((1 << (1)) - 1));
}
void *func_020f2f38(NNSiFndExpHeapHead *pEHHead, NNSiFndExpHeapMBlockHead *pMBHeadFree, void *mblock, u32 size, u16 direction);
void *func_020f2e70(NNSiFndHeapHead *pHeapHd, u32 size, int alignment) {
    NNSiFndExpHeapHead *pExpHeapHd = GetExpHeapHeadPtrFromHeapHead(pHeapHd);
    const BOOL bAllocFirst         = GetAllocMode(pExpHeapHd) == NNS_FND_EXPHEAP_ALLOC_MODE_FIRST;

    NNSiFndExpHeapMBlockHead *pMBlkHd      = 0;
    NNSiFndExpHeapMBlockHead *pMBlkHdFound = 0;
    u32 foundSize                          = 0xffffffff;
    void *foundMBlock                      = 0;

    for (pMBlkHd = pExpHeapHd->mbFreeList.head; pMBlkHd; pMBlkHd = pMBlkHd->pMBHeadNext) {
        void *const mblock    = GetMemPtrForMBlock(pMBlkHd);
        void *const reqMBlock = ((void *) (((NNSiGetUIntPtr(mblock)) + (alignment - 1)) & ~(alignment - 1)));
        const u32 offset      = GetOffsetFromPtr(mblock, reqMBlock);

        if (pMBlkHd->blockSize >= size + offset && foundSize > pMBlkHd->blockSize) {
            pMBlkHdFound = pMBlkHd;
            foundSize    = pMBlkHd->blockSize;
            foundMBlock  = reqMBlock;

            if (bAllocFirst || foundSize == size) {
                break;
            }
        }
    }

    if (!pMBlkHdFound) {
        return 0;
    }

    return func_020f2f38(pExpHeapHd, pMBlkHdFound, foundMBlock, size, NNS_FND_EXPHEAP_ALLOC_DIR_FRONT);
}
