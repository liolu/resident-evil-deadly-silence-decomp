/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02068618 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/fnd/fnd_expheap.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
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
void *func_020f2e70(UnkExpHeap *heap, u32 size, u32 alignment);
void *func_020f2dac(UnkExpHeap *heap, u32 size, u32 alignment);
void *func_020f2c18(UnkExpHeap *heap, u32 size, int alignment) {
    if (size == 0) {
        size = 1;
    }
    size = ((((4) - 1) + (u32) (size)) & ~((4) - 1));
    if (alignment >= 0) {
        return func_020f2e70(heap, size, alignment);
    } else {
        return func_020f2dac(heap, size, -alignment);
    }
}
