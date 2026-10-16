/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */

typedef unsigned short u16;
typedef int s32;
typedef volatile u16 vu16;
typedef struct UnkCtrdgCycles {
    s32 unk_00;
    s32 unk_04;
} UnkCtrdgCycles;
extern void func_0210fb08(const UnkCtrdgCycles *cycles);

/* func_0205eb08 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/ctrdg/ctrdg_common.c (license: none),
 * reused by tools/donor_match.py */
void func_0210fb08(const UnkCtrdgCycles *cycles) {
    (*(vu16 *) 0x04000204) = (u16) ((cycles->unk_00 << 2) | ((*(vu16 *) 0x04000204) & ~0xC));
    (*(vu16 *) 0x04000204) = (u16) ((cycles->unk_04 << 4) | ((*(vu16 *) 0x04000204) & ~0x10));
}
