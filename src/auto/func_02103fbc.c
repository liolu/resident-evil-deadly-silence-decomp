/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* OS_InitContext from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/os/os_init_context.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pcPlus4;
    u32 spSvc;
    u8 cpContext[0x1c];
} OSContext;
extern void func_02103fbc(OSContext *context, u32 pc, u32 sp);
// clang-format off
asm void func_02103fbc(OSContext *context, u32 pc, u32 sp)
{
    add r1, r1, #4
    str r1, [r0, #0x40]
    str r2, [r0, #0x44]
    sub r2, r2, #0x40
    str r2, [r0, #0x38]
    ands r1, r1, #1
    movne r1, #0x3f
    moveq r1, #0x1f
    str r1, [r0]
    mov r1, #0
    str r1, [r0, #0x4]
    str r1, [r0, #0x8]
    str r1, [r0, #0xc]
    str r1, [r0, #0x10]
    str r1, [r0, #0x14]
    str r1, [r0, #0x18]
    str r1, [r0, #0x1c]
    str r1, [r0, #0x20]
    str r1, [r0, #0x24]
    str r1, [r0, #0x28]
    str r1, [r0, #0x2c]
    str r1, [r0, #0x30]
    str r1, [r0, #0x34]
    str r1, [r0, #0x3c]
    bx lr
}
// clang-format on
