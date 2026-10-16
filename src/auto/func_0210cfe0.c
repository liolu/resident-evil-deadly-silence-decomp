/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned char u8;
typedef volatile u32 vu32;
typedef volatile u8 vu8;
extern void func_0210cfe0(u32 hi, u32 lo);

/* func_0205de44 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/card/card_rom.c (license: none), reused by
 * tools/donor_match.py */
void func_0210cfe0(u32 hi, u32 lo) {
    while (*(vu32 *) 0x040001A4 & 0x80000000) {
    }
    *(vu8 *) 0x040001A1 = 0xC0;
    *(vu8 *) 0x040001A8 = (u8) (hi >> 24);
    *(vu8 *) 0x040001A9 = (u8) (hi >> 16);
    *(vu8 *) 0x040001AA = (u8) (hi >> 8);
    *(vu8 *) 0x040001AB = (u8) (hi >> 0);
    *(vu8 *) 0x040001AC = (u8) (lo >> 24);
    *(vu8 *) 0x040001AD = (u8) (lo >> 16);
    *(vu8 *) 0x040001AE = (u8) (lo >> 8);
    *(vu8 *) 0x040001AF = (u8) (lo >> 0);
}
