/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02068440 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/fnd/fnd_expheap.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef s32 BOOL;
typedef struct UnkFndLink {
    void *unk_00;
    void *unk_04;
} UnkFndLink;
typedef struct UnkFndList {
    void *unk_00;
    void *unk_04;
    u16 unk_08;
    u16 unk_0a;
} UnkFndList;
typedef struct UnkFndHeapHead {
    u32 unk_00;
    UnkFndLink unk_04;
    UnkFndList unk_0c;
    void *unk_18;
    void *unk_1c;
    u32 unk_20;
} UnkFndHeapHead;
typedef struct UnkExpMBlock {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    struct UnkExpMBlock *unk_08;
    struct UnkExpMBlock *unk_0c;
} UnkExpMBlock;
typedef struct UnkExpMBlockList {
    UnkExpMBlock *unk_00;
    UnkExpMBlock *unk_04;
} UnkExpMBlockList;
typedef struct UnkExpHeapHead {
    UnkExpMBlockList unk_00;
    UnkExpMBlockList unk_08;
    u16 unk_10;
    u16 unk_12;
} UnkExpHeapHead;
typedef struct UnkExpHeap {
    UnkFndHeapHead unk_00;
    UnkExpHeapHead unk_24;
} UnkExpHeap;
static inline u16 GetAllocMode(UnkExpHeapHead *exp) {
    return (u16) (((exp->unk_12) >> (0)) & ((1 << (1)) - 1));
}
static inline void *GetMemPtrForMBlock(UnkExpMBlock *block) {
    return (void *) ((u32) block + sizeof(UnkExpMBlock));
}
void *func_020f2f38(UnkExpHeapHead *exp, UnkExpMBlock *block, void *mem, u32 size, u16 direction);
void *func_020f2dac(UnkExpHeap *heap, u32 size, u32 alignment) {
    UnkExpHeapHead *exp = &heap->unk_24;
    BOOL first          = GetAllocMode(exp) == 0;
    UnkExpMBlock *found = 0;
    UnkExpMBlock *block;
    u32 foundSize  = 0xffffffff;
    void *foundMem = 0;

    for (block = exp->unk_00.unk_04; block != 0; block = block->unk_08) {
        void *mem    = GetMemPtrForMBlock(block);
        void *memEnd = (void *) (block->unk_04 + (u32) mem);
        void *reqMem = (void *) ((u32) ((u32) memEnd - size) & ~((alignment) -1));
        s32 offset   = (s32) ((u32) reqMem - (u32) mem);

        if (offset >= 0 && foundSize > block->unk_04) {
            found     = block;
            foundSize = block->unk_04;
            foundMem  = reqMem;
            if (first || foundSize == size) {
                break;
            }
        }
    }

    if (found == 0) {
        return 0;
    }
    return func_020f2f38(exp, found, foundMem, size, 1);
}
