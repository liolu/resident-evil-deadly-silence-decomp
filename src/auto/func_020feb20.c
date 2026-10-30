/* compiler: 1.2/sp2p3 */
/* FX_InvAsync from projets/rayman-rr/src/nitro/fx/fx_cp_4.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef long fx32;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
void func_020feb20(fx32 x) {
    *(volatile u16 *) 0x04000280 = 1;
    *(volatile u64 *) 0x04000290 = (u64) 0x1000 << 32;
    *(volatile u64 *) 0x04000298 = (u32) x;
}
