/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* OS_GetLockID from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_spinlock.c (license: none), reused by
 * tools/donor_match.py */
typedef int s32;
extern s32 func_02102a50(void);
// clang-format off
asm s32 func_02102a50(void) {
    ldr r3, =0x027fffb0
    ldr r1, [r3]
    clz r2, r1
    cmp r2, #0x20
    movne r0, #0x40
    bne _found
    add r3, r3, #4
    ldr r1, [r3]
    clz r2, r1
    cmp r2, #0x20
    ldr r0, =0xfffffffd
    bxeq lr
    mov r0, #0x60
_found:
    add r0, r0, r2
    mov r1, #0x80000000
    mov r1, r1, lsr r2
    ldr r2, [r3]
    bic r2, r2, r1
    str r2, [r3]
    bx lr
}
// clang-format on
