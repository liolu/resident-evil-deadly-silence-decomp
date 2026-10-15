/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02068a5c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/bin/bin_block.c (license: none), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct UnkBinFileHeader {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u32 unk_08;
    u16 unk_0c;
    u16 unk_0e;
} UnkBinFileHeader;
typedef struct UnkBinBlockHeader {
    u32 unk_00;
    u32 unk_04;
} UnkBinBlockHeader;
extern UnkBinBlockHeader *func_020f3c40(UnkBinFileHeader *header, u32 kind);
UnkBinBlockHeader *func_020f3c40(UnkBinFileHeader *header, u32 kind) {
    UnkBinBlockHeader *block = (UnkBinBlockHeader *) ((u32) header + header->unk_0c);
    u16 i;

    for (i = 0; i < header->unk_0e; i++) {
        if (block->unk_00 == kind) {
            return block;
        }
        block = (UnkBinBlockHeader *) ((u32) block + block->unk_04);
    }
    return 0;
}
