/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s16 func_020e15fc(s32);                             /* extern */
M2C_UNK func_020e167c(s32, s16);                    /* extern */
extern void *data_02137264;

s32 func_02005ae8(void) {
    s16 temp_r1;
    s32 var_r0;

    var_r0  = 0;
    temp_r1 = M2C_FIELD(data_02137264, s16 *, 6);
    if ((s32) temp_r1 > 0) {
        M2C_FIELD(data_02137264, s16 *, 4) = func_020e15fc(M2C_FIELD(data_02137264, s32 *, 0x540));
        M2C_FIELD(data_02137264, s16 *, 4) = (s16) (M2C_FIELD(data_02137264, s16 *, 4) + M2C_FIELD(data_02137264, s16 *, 6));
        if ((s32) M2C_FIELD(data_02137264, s16 *, 4) > 0) {
            M2C_FIELD(data_02137264, s16 *, 4) = 0;
            M2C_FIELD(data_02137264, s16 *, 6) = 0;
        }
        func_020e167c(M2C_FIELD(data_02137264, s32 *, 0x540), M2C_FIELD(data_02137264, s16 *, 4));
        return 1;
    }
    if ((s32) temp_r1 < 0) {
        M2C_FIELD(data_02137264, s16 *, 4) = func_020e15fc(M2C_FIELD(data_02137264, s32 *, 0x540));
        M2C_FIELD(data_02137264, s16 *, 4) = (s16) (M2C_FIELD(data_02137264, s16 *, 4) + M2C_FIELD(data_02137264, s16 *, 6));
        if ((s32) M2C_FIELD(data_02137264, s16 *, 4) < -0x3C0) {
            M2C_FIELD(data_02137264, s16 *, 4) = -0x3C0;
            M2C_FIELD(data_02137264, s16 *, 6) = 0;
        }
        func_020e167c(M2C_FIELD(data_02137264, s32 *, 0x540), M2C_FIELD(data_02137264, s16 *, 4));
        var_r0 = 1;
    }
    return var_r0;
}
