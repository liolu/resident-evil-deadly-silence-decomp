/* compiler: 1.2/sp2p3 -O2 */
#include "m2c.h"

s32 func_020dc00c(s32);                             /* extern */
M2C_UNK func_020dc054(s32);                         /* extern */
s32 func_020e3470(s32);                             /* extern */

void func_020dfcfc(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    s32 sp0;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 var_r0;
    s32 var_r7;
    u32 temp_r0_2;
    u32 temp_r0_3;
    void **temp_r0;
    void *var_r6;

    sp0    = M2C_FIELD(arg0, s32 *, 0xC);
    var_r7 = 0;
    if (func_020dc00c(M2C_FIELD(arg0, s32 *, 4)) > 0) {
        var_r6 = arg0 + 0x1C;
        do {
            temp_r0 = M2C_FIELD((arg0 + (var_r7 * 4)), void ***, 0xC);
            M2C_FIELD(*temp_r0, M2C_UNK(**)(void **, s32, M2C_UNK, void *), 0x18)(temp_r0, 0, 0x4000, var_r6);
            var_r7 += 1;
            var_r6 += 8;
        } while (var_r7 < func_020dc00c(M2C_FIELD(arg0, s32 *, 4)));
    }
    temp_r0_2 = M2C_FIELD(arg0, s32 *, 0x1C) - func_020e3470(sp0);
    *arg1     = (s32) (temp_r0_2 + (temp_r0_2 >> 0x1F)) >> 1;
    temp_r0_3 = M2C_FIELD(arg0, u32 *, 0x20);
    temp_r1   = M2C_FIELD(arg0, s32 *, 0x38);
    var_r0    = (s32) (temp_r0_3 + (temp_r0_3 >> 0x1F)) >> 1;
    if (var_r0 >= temp_r1) {
        var_r0 = temp_r1;
    }
    *arg2     = var_r0;
    temp_r1_2 = M2C_FIELD(arg0, s32 *, 0x3C);
    if (temp_r1_2 >= 0) {
        *arg3 = temp_r1_2 - M2C_FIELD(arg0, s32 *, 0x40);
    } else {
        *arg3 = 0x1FFFFFFF;
    }
    func_020dc054(M2C_FIELD(arg0, s32 *, 4));
}
