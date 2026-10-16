/* func_02017894 from projets/rayman-rr/src/auto/func_02017894.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
// clang-format off
asm void func_021025d8(void) {
    stmfd sp!, {r4, r5, r6, r7, r8}
    ldmia r0!, {r2, r3, r4, r5, r6, r7, r8, ip}
    stmia r1, {r2, r3, r4, r5, r6, r7, r8, ip}
    ldmia r0!, {r2, r3, r4, r5, r6, r7, r8, ip}
    stmia r1, {r2, r3, r4, r5, r6, r7, r8, ip}
    ldmfd sp!, {r4, r5, r6, r7, r8}
    bx lr
}
// clang-format on
