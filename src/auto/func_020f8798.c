/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0206e8c0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_res_struct.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct UnkBinFileHeader {
    u32 signature;
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 dataBlocks;
} UnkBinFileHeader;
void *func_020f8798(const UnkBinFileHeader *file) {
    return (u8 *) file + *(const u32 *) ((u8 *) file + file->headerSize);
}
