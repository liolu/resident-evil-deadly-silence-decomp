/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* NNS_FndFreeToExpHeap from https://github.com/RonyxDumb/mkds src/arm9/020176c0_Mem_Exp_GetAllocatableSize.c (license: none),
 * reused by tools/donor_match.py */
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
typedef NNSiFndHeapHead *NNSFndHeapHandle;
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
extern void func_020f2a50(NNSFndHeapHandle heap, void *memBlock);
typedef u32 NNSiUIntPtr;
inline NNSiUIntPtr NNSiGetUIntPtr(const void *ptr) {
    return (NNSiUIntPtr) ptr;
}
inline void *AddU32ToPtr(void *ptr, u32 val) {
    return (void *) (NNSiGetUIntPtr(ptr) + val);
}
inline void *SubU32ToPtr(void *ptr, u32 val) {
    return (void *) (NNSiGetUIntPtr(ptr) - val);
}
typedef struct NNSiMemRegion NNSiMemRegion;
struct NNSiMemRegion {
    void *start;
    void *end;
};
static inline NNSiFndExpHeapHead *GetExpHeapHeadPtrFromHeapHead(NNSiFndHeapHead *pHHead) {
    return AddU32ToPtr(pHHead, sizeof(NNSiFndHeapHead));
}
static inline NNSiFndExpHeapHead *GetExpHeapHeadPtrFromHandle(NNSFndHeapHandle heap) {
    return GetExpHeapHeadPtrFromHeapHead(heap);
}
static inline NNSiFndExpHeapMBlockHead *GetMBlockHeadPtr(void *memBlock) {
    return SubU32ToPtr(memBlock, sizeof(NNSiFndExpHeapMBlockHead));
}
void func_020f31d8(NNSiMemRegion *region, NNSiFndExpHeapMBlockHead *block);
NNSiFndExpHeapMBlockHead *func_020f31b0(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block);
BOOL func_020f2cb4(NNSiFndExpHeapHead *pEHHead, const NNSiMemRegion *pRegion);
void func_020f2a50(NNSFndHeapHandle heap, void *memBlock) {
    ((void) 0);

    {
        NNSiFndHeapHead *pHeapHd          = heap;
        NNSiFndExpHeapHead *pExpHeapHd    = GetExpHeapHeadPtrFromHandle(pHeapHd);
        NNSiFndExpHeapMBlockHead *pMBHead = GetMBlockHeadPtr(memBlock);
        NNSiMemRegion region;

        ((void) 0);

        func_020f31d8(&region, pMBHead);
        (void) func_020f31b0(&pExpHeapHd->mbUsedList, pMBHead);
        (void) func_020f2cb4(pExpHeapHd, &region);
    }
}
