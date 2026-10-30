/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02059824 from https://github.com/tangosdev/sm64ds-decomp src/unnamed/arm9/0205/func_02059824.c (license: MIT), reused
 * by tools/donor_match.py */
extern void func_02105054(void);
// clang-format off
asm void func_02105044(void) {
    stmdb sp!, {lr}
    bl func_02105054
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
