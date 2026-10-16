/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned short u16;
typedef unsigned long long u64;
struct ARMMathState {
    u64 div_numer;
    u64 div_denom;
    u64 sqrt;
    u16 div_mode;
    u16 sqrt_mode;
};

/* Arm_MathContext_Load from https://github.com/RonyxDumb/mkds src/arm9/02146bb8_Arm_MathContext_Load.c (license: none), reused
 * by tools/donor_match.py */
void func_02109b60(const struct ARMMathState *s) {
    *(volatile u64 *) 0x4000290 = s->div_numer;
    *(volatile u64 *) 0x4000298 = s->div_denom;
    *(volatile u16 *) 0x4000280 = s->div_mode;
    *(volatile u64 *) 0x40002b8 = s->sqrt;
    *(volatile u16 *) 0x40002b0 = s->sqrt_mode;
}
