/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206a458 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_kernel.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef struct UnkResAnmHeader {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
} UnkResAnmHeader;
typedef void (*UnkAnmFunc)(void *result, struct UnkAnmObj *anm, u32 dataIdx);
typedef struct UnkAnmObj {
    s32 unk_00;
    s32 unk_04;
    UnkResAnmHeader *unk_08;
    UnkAnmFunc unk_0c;
    struct UnkAnmObj *unk_10;
    void *unk_14;
    u8 unk_18;
    u8 unk_19;
    u16 unk_1a[1];
} UnkAnmObj;
void func_020f4524(u32 *bits, UnkAnmObj *anm) {
    if (anm == 0) {
        return;
    }
    do {
        int i;

        for (i = 0; i < anm->unk_19; i++) {
            if (anm->unk_1a[i] & 0x100) {
                bits[i >> 5] |= 1 << (i & 31);
            }
        }
        anm = anm->unk_10;
    } while (anm != 0);
}
