/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_0211851c(M2C_UNK, M2C_UNK);

void func_0208c150(s32 arg0, s32 arg1) {
    s32 var_r0;
    s32 var_r6;

    M2C_FIELD(arg0, s16 *, 0x28C) = (s16) (M2C_FIELD(arg0, s16 *, 0x28C) & 0xFFF);
    M2C_FIELD(arg0, s16 *, 0x28E) = (s16) (M2C_FIELD(arg0, s16 *, 0x28E) & 0xFFF);
    var_r0 = M2C_FIELD(arg0, s16 *, 0x290) - M2C_FIELD(arg0, s16 *, 0x28C);
    if (var_r0 < 0) {
        if (var_r0 < -0x800) {
            var_r0 += 0x1000;
        }
    } else if (var_r0 > 0x800) {
        var_r0 -= 0x1000;
    }
    var_r6 = M2C_FIELD(arg0, s16 *, 0x292) - M2C_FIELD(arg0, s16 *, 0x28E);
    if (var_r6 < 0) {
        if (var_r6 < -0x800) {
            var_r6 += 0x1000;
        }
    } else if (var_r6 > 0x800) {
        var_r6 -= 0x1000;
    }
    M2C_FIELD(arg0, s16 *, 0x294) = (s16) func_0211851c(var_r0, arg1);
    M2C_FIELD(arg0, s16 *, 0x296) = (s16) func_0211851c(var_r6, arg1);
    M2C_FIELD(arg0, s16 *, 0x298) = 0;
    M2C_FIELD(arg0, s16 *, 0x29A) = 0;
    M2C_FIELD(arg0, s16 *, 0x29C) = (s16) arg1;
}
