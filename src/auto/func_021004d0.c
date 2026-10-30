/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02064cf4 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/gx_bgcnt.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
void *func_021004d0(void) {
    u32 bgMode = (*(vu32 *) 0x04001000) & 7;
    u32 bgcnt  = (*(vu16 *) ((0x04001000) | 0xe));
    u32 block  = (bgcnt & 0x1f00) >> 8;

    switch (bgMode) {
        case 0:
        case 1:
        case 2:
            return (void *) (0x6200000 + block * 0x800);
        case 3:
        case 4:
        case 5:
            if (bgcnt & 0x80) {
                return (void *) (0x6200000 + block * 0x4000);
            } else {
                return (void *) (0x6200000 + block * 0x800);
            }
        case 6:
            return 0;
        default:
            return 0;
    }
}
