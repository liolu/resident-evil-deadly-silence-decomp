/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206816c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/fnd/fnd_expheap.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct UnkExpMBlock {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    struct UnkExpMBlock *unk_08;
    struct UnkExpMBlock *unk_0c;
} UnkExpMBlock;
typedef struct UnkMemRegion {
    void *unk_00;
    void *unk_04;
} UnkMemRegion;
static inline void *GetMemPtrForMBlock(UnkExpMBlock *block) {
    return (void *) ((u32) block + sizeof(UnkExpMBlock));
}
UnkExpMBlock *func_020f3150(UnkMemRegion *region, u16 signature) {
    UnkExpMBlock *block = (UnkExpMBlock *) region->unk_00;

    block->unk_00 = signature;
    block->unk_02 = 0;
    block->unk_04 = (u32) region->unk_04 - (u32) GetMemPtrForMBlock(block);
    block->unk_08 = 0;
    block->unk_0c = 0;
    return block;
}
