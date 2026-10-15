/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* Heap_TakeFromFreeBlock from https://github.com/sturmds/advance-wars-dual-strike-decomp
 * src/game/main/mem/heap_take_from_free_block.c (license: CC0-1.0), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct ListLink {
    void *prev;
    void *next;
} ListLink;
typedef struct LinkList {
    void *head;
    void *tail;
    u16 count;
    u16 linkOffset;
} LinkList;
typedef struct HeapHead {
    u32 signature;
    ListLink link;
    LinkList children;
    void *start;
    void *end;
    u32 options;
} HeapHead;
typedef struct HeapBlock {
    u16 signature;
    u16 attribute;
    u32 size;
    struct HeapBlock *prev;
    struct HeapBlock *next;
} HeapBlock;
typedef struct HeapBlockList {
    HeapBlock *head;
    HeapBlock *tail;
} HeapBlockList;
typedef struct HeapRegion {
    void *start;
    void *end;
} HeapRegion;
typedef struct ExpHeapData {
    HeapBlockList freeBlocks;
    HeapBlockList usedBlocks;
    u16 groupId;
    u16 allocMode;
} ExpHeapData;
typedef struct ExpHeap {
    HeapHead head;
    ExpHeapData data;
} ExpHeap;
extern void *func_020f2f38(ExpHeapData *data, HeapBlock *freeBlock, void *memory, u32 size, u16 fromTop);
extern HeapBlock *func_020f3150(HeapRegion *region, u16 signature);
extern void func_020f31d8(HeapRegion *region, HeapBlock *block);
extern HeapBlock *func_020f3180(HeapBlockList *list, HeapBlock *block, HeapBlock *prev);
extern HeapBlock *func_020f31b0(HeapBlockList *list, HeapBlock *block);
extern void func_021060a4(u32 value, void *dest, u32 size);
static inline void HeapBlock_SetFromTop(HeapBlock *block, u16 fromTop) {
    block->attribute &= ~0x8000;
    block->attribute |= (fromTop & 1) << 15;
}
static inline void HeapBlock_SetPadding(HeapBlock *block, u16 padding) {
    block->attribute &= ~0x7F00;
    block->attribute |= (padding & 0x7F) << 8;
}
static inline void HeapBlock_SetGroupId(HeapBlock *block, u8 groupId) {
    block->attribute &= ~0xFF;
    block->attribute |= groupId;
}
void *func_020f2f38(ExpHeapData *data, HeapBlock *freeBlock, void *memory, u32 size, u16 fromTop) {
    HeapRegion front;
    HeapRegion back;
    HeapRegion used;
    HeapBlock *prev;
    HeapBlock *block;
    volatile u32 fill;
    u32 usedSize;
    u8 *blockStart;

    func_020f31d8(&front, freeBlock);
    blockStart = (u8 *) memory - sizeof(HeapBlock);
    back.end   = front.end;
    front.end  = blockStart;
    back.start = (void *) (size + (u32) memory);

    prev = func_020f31b0(&data->freeBlocks, freeBlock);

    if ((u32) front.end - (u32) front.start < sizeof(HeapBlock)) {
        front.end = front.start;
    } else {
        prev = func_020f3180(&data->freeBlocks, func_020f3150(&front, 0x4652), prev);
    }

    if ((u32) back.end - (u32) back.start < sizeof(HeapBlock)) {
        back.start = back.end;
    } else {
        func_020f3180(&data->freeBlocks, func_020f3150(&back, 0x4652), prev);
    }

    usedSize = (u32) back.start - (u32) front.end;

    if ((u16) (((ExpHeap *) ((u32) data - sizeof(HeapHead)))->head.options & 0xFF) & 1) {
        fill = 0;
        func_021060a4(fill, front.end, usedSize);
    }

    used.start = blockStart;
    used.end   = back.start;
    block      = func_020f3150(&used, 0x5544);
    HeapBlock_SetFromTop(block, fromTop);
    HeapBlock_SetPadding(block, (u32) block - (u32) front.end);
    HeapBlock_SetGroupId(block, data->groupId);
    func_020f3180(&data->usedBlocks, block, data->usedBlocks.tail);
    return memory;
}
