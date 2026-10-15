/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* InitExpHeap from https://github.com/RonyxDumb/mkds src/arm9/020176c0_Mem_Exp_GetAllocatableSize.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
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
inline void *AddU32ToPtr(void *ptr, u32 val) {
    return (void *) (NNSiGetUIntPtr(ptr) + val);
}
extern void func_020f28fc(NNSiFndHeapHead *pHeapHd, u32 signature, void *heapStart, void *heapEnd, u16 optFlag);
typedef struct NNSiMemRegion NNSiMemRegion;
struct NNSiMemRegion {
    void *start;
    void *end;
};
static inline NNSiFndExpHeapHead *GetExpHeapHeadPtrFromHeapHead(NNSiFndHeapHead *pHHead) {
    return AddU32ToPtr(pHHead, sizeof(NNSiFndHeapHead));
}
static inline void SetAllocMode(NNSiFndExpHeapHead *pEHHead, u16 mode) {
    do {
        u32 maskBits = (u32) ((1 << (1)) - 1);
        u32 newVal   = (mode) &maskBits;
        (void) (maskBits <<= 0);
        (pEHHead->feature) &= ~maskBits;
        (pEHHead->feature) |= newVal << (0);
    } while (0);
    ;
}
NNSiFndExpHeapMBlockHead *func_020f3150(const NNSiMemRegion *pRegion, u16 signature);
static inline NNSiFndExpHeapMBlockHead *InitFreeMBlock(const NNSiMemRegion *pRegion) {
    return func_020f3150(pRegion, ('FR'));
}
NNSiFndHeapHead *func_020f30cc(void *startAddress, void *endAddress, u16 optFlag) {
    NNSiFndHeapHead *pHeapHd       = startAddress;
    NNSiFndExpHeapHead *pExpHeapHd = GetExpHeapHeadPtrFromHeapHead(pHeapHd);

    func_020f28fc(pHeapHd, ('EXPH'), AddU32ToPtr(pExpHeapHd, sizeof(NNSiFndExpHeapHead)), endAddress, optFlag);

    pExpHeapHd->groupID = 0;
    pExpHeapHd->feature = 0;
    SetAllocMode(pExpHeapHd, NNS_FND_EXPHEAP_ALLOC_MODE_FIRST);

    {
        NNSiFndExpHeapMBlockHead *pMBHead;
        NNSiMemRegion region;

        region.start = pHeapHd->heapStart;
        region.end   = pHeapHd->heapEnd;

        pMBHead = InitFreeMBlock(&region);

        pExpHeapHd->mbFreeList.head = pMBHead;
        pExpHeapHd->mbFreeList.tail = pMBHead;
        pExpHeapHd->mbUsedList.head = 0;
        pExpHeapHd->mbUsedList.tail = 0;

        return pHeapHd;
    }
}
