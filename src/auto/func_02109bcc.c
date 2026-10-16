/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned short u16;
typedef unsigned int u32;
struct Pair {
    u32 a, b;
};
struct ARMMathState {
    struct Pair p0;
    struct Pair p8;
    struct Pair p10;
    u16 h18;
    u16 h1a;
};

/* Arm_MathContext_Save from https://github.com/RonyxDumb/mkds src/arm9/02146c24_Arm_MathContext_Save.c (license: none), reused
 * by tools/donor_match.py */
void func_02109bcc(struct ARMMathState *s) {
    s->p0  = *(struct Pair *) 0x4000290;
    s->p8  = *(struct Pair *) 0x4000298;
    s->h18 = (u16) (*(volatile u16 *) 0x4000280 & 3);
    s->p10 = *(struct Pair *) 0x40002b8;
    s->h1a = (u16) (*(volatile u16 *) 0x40002b0 & 1);
}
