/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02065088 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/g3x.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
extern void func_02100d4c(void);
extern void func_02100c9c(void);
extern void func_02100a24(void);
void func_02100e08(void) {
    func_02100d4c();
    (*(vu32 *) 0x04000504) = 0;
    while ((*(vu32 *) 0x04000600) & 0x8000000) {
    }
    (*(vu16 *) 0x04000060) = 0;
    (*(vu32 *) 0x04000600) = 0;
    (*(vu32 *) 0x04000010) = 0;
    (*(vu16 *) 0x04000060) |= 0x2000;
    (*(vu16 *) 0x04000060) |= 0x1000;
    (*(vu16 *) 0x04000060) &= ~0x3002;
    (*(vu16 *) 0x04000060) = ((*(vu16 *) 0x04000060) & ~0x3000) | 0x10;
    (*(vu16 *) 0x04000060) &= (u16) ~0x3004;
    (*(vu32 *) 0x04000600) |= 0x8000;
    (*(vu32 *) 0x04000600) = ((*(vu32 *) 0x04000600) & ~0xc0000000) | 0x80000000;
    func_02100c9c();
    (*(vu32 *) 0x04000350) = 0;
    (*(vu16 *) 0x04000354) = 0x7fff;
    (*(vu16 *) 0x04000356) = 0;
    (*(vu32 *) 0x04000358) = 0;
    (*(vu16 *) 0x0400035c) = 0;
    (*(vu16 *) ((0x04000000) | 0x8)) &= ~3;
    func_02100a24();
    (*(vu32 *) 0x040004a4) = 0x1f0080;
    (*(vu32 *) 0x040004a8) = 0;
    (*(vu32 *) 0x040004ac) = 0;
}
void func_02100d4c(void);
void func_02100c9c(void);
void func_02100a24(void);
