/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef int s32;
typedef volatile u32 vu32;
extern void func_02105528(void);

/* func_02067468 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/mi_dma.c (license: none), reused by
 * tools/donor_match.py */
void func_02105874(u32 dmaNo, u32 dmaType) {
    s32 i;
    vu32 *cnt = &(((vu32 *) 0x040000b0)[(0) * 3 + 2]);

    for (i = 0; i < 3; i++, cnt += 3) {
        u32 dmaCnt;
        if (i == dmaNo) {
            continue;
        }
        dmaCnt = *cnt;
        if (!(dmaCnt & 0x80000000)) {
            continue;
        }
        dmaCnt &= 0x38000000;
        if (dmaCnt == dmaType) {
            continue;
        }
        if (dmaCnt == 0x08000000 && dmaType == 0x10000000) {
            continue;
        }
        if (dmaCnt == 0x10000000 && dmaType == 0x08000000) {
            continue;
        }
        if (dmaCnt == 0x18000000 || dmaCnt == 0x20000000 || dmaCnt == 0x28000000 || dmaCnt == 0x30000000 ||
            dmaCnt == 0x38000000 || dmaCnt == 0x08000000 || dmaCnt == 0x10000000) {
            func_02105528();
        }
    }
}
