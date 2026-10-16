/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned short u16;
typedef volatile u32 vu32;
typedef volatile u16 vu16;

/* func_020673ec from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/mi_dma.c (license: none), reused by
 * tools/donor_match.py */
void func_02105928(u32 dmaNo) {
    u32 e = func_021054ac();
    (((vu16 *) 0x040000b0)[(dmaNo) * 6 + 5]) &= ~0x3a00;
    (((vu16 *) 0x040000b0)[(dmaNo) * 6 + 5]) &= ~0x8000;
    (((vu16 *) 0x040000b0)[(dmaNo) * 6 + 5]);
    (((vu16 *) 0x040000b0)[(dmaNo) * 6 + 5]);
    if (dmaNo == 0) {
        vu32 *p = (vu32 *) (0x040000b0 + dmaNo * 12);
        p[0]    = 0;
        p[1]    = 0;
        p[2]    = 0x81400001;
    }
    func_021054c0(e);
}
