#include "m2c.h"

/* VRAM block copy: `src` = r0, destination byte offset = r1, byte count = r2.
 *
 * The routine loads the VRAM bank base into `ip` once (`mov ip, #0x6600000`) and then adds
 * the caller's byte offset with a register operand in both branches (`add r2, ip, lr` /
 * `add r1, ip, lr`).  mwccarm never materialises a constant that way: for `x + 0x06600000`
 * it always folds the constant into the immediate form (`add r2, lr, #0x6600000`), and it
 * only keeps a value in a register when that value is not statically known (a call result)
 * or when the constant does not fit an ARM immediate (then it is a literal-pool `ldr`).
 *
 * Probed here before falling back to assembly (files build/agent_work/func_02101f34/v1..v12.c):
 *  - control flow: if+return, if/else, inverted condition (early return on the else side);
 *  - value forms for the base: literal used twice, single local computed before the branch
 *    (s32/u32), `register u32` local, `const`/`static const` local, `u8 *` pointer base,
 *    3 uses of the constant;
 *  - callee prototypes: func_02105c14 as 3 and 4 args (it really takes r3 = length),
 *    func_021060b8 as 3, 4 and 5 args (the 5th pushed a stack argument and changed the size);
 *  - compiler profiles: 2.0/sp1p5 and 1.2/sp2p3, plus 1.2/sp2p3 -proc arm7tdmi.
 * The closest form is 1.2/sp2p3 with the real prototypes: it reproduces the whole function,
 * including the duplicated `pop {r4, lr}; bx lr` epilogues (2.0/sp1p5 instead tail-calls with
 * `pop {r4, pc}`), and is short by exactly one instruction - the `mov ip, #0x6600000`.
 * The twin GX_LoadOBJ (same code with 0x0640000, see src/auto/GX_LoadOBJ.c) was probed
 * with ~150 shapes and every installed mwccarm profile and landed on the same conclusion.
 * This routine is therefore hand-written SDK block-transfer assembly.
 */
extern void func_02105c14();

extern void func_021060b8();

extern s32 data_02136b8c;

// clang-format on

// clang-format off
asm void func_02101f34(void) {
    stmfd sp!, {r4, lr}
    ldr r3, =data_02136b8c
    mov r4, r0
    ldr r0, [r3]
    mvn ip, #0x0
    mov lr, r1
    mov r3, r2
    cmp r0, ip
    mov ip, #0x6600000
    beq L_02017188
    cmp r3, #0x30
    bls L_02017188
    mov r1, r4
    add r2, ip, lr
    bl func_02105c14
    ldmfd sp!, {r4, lr}
    bx lr
L_02017188:
    mov r0, r4
    mov r2, r3
    add r1, ip, lr
    bl func_021060b8
    ldmfd sp!, {r4, lr}
    bx lr
}
