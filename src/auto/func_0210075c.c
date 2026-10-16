/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02002960 from projets/farm-frenzy/src/donor/func_02002960.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
void *func_0210075c(void) {
    s32 blockOffset = ((*(vu16 *) ((0x04000000) | 0x8)) & 0x1f00) >> 8;
    u32 offset      = ((*(vu32 *) 0x04000000) & 0x38000000) >> 27;
    return (void *) (0x6000000 + offset * 0x10000 + blockOffset * 0x800);
}
