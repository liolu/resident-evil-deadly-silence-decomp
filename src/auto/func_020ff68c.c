/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef volatile u8 vu8;
extern u16 data_021587d4;
extern void func_02105738(u16 bank, u16 lockId);

/* DisableBank from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/gx_vramcnt.c (license: none), reused by
 * tools/donor_match.py */
s32 func_020ff68c(u16 *bank) {
    s32 vram = *bank;
    *bank    = 0;

    if (vram & 0x001) {
        (*(vu8 *) 0x04000240) = 0;
    }
    if (vram & 0x002) {
        (*(vu8 *) 0x04000241) = 0;
    }
    if (vram & 0x004) {
        (*(vu8 *) 0x04000242) = 0;
    }
    if (vram & 0x008) {
        (*(vu8 *) 0x04000243) = 0;
    }
    if (vram & 0x010) {
        (*(vu8 *) 0x04000244) = 0;
    }
    if (vram & 0x020) {
        (*(vu8 *) 0x04000245) = 0;
    }
    if (vram & 0x040) {
        (*(vu8 *) 0x04000246) = 0;
    }
    if (vram & 0x080) {
        (*(vu8 *) 0x04000248) = 0;
    }
    if (vram & 0x100) {
        (*(vu8 *) 0x04000249) = 0;
    }
    func_02105738((u16) vram, data_021587d4);
    return vram;
}
