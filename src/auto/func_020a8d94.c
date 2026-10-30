/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020ac214(M2C_UNK);                         /* extern */
extern M2C_UNK data_0213bdcc;

s32 func_020a8d94(void *arg0) {
    s16 temp_r1;
    void *var_r0;

    var_r0  = arg0;
    temp_r1 = M2C_FIELD(var_r0, s16 *, 0xA6);
    if ((temp_r1 == 0) || (M2C_FIELD(var_r0, s16 *, 0xA6) = (s16) (temp_r1 + 1), ((s32) M2C_FIELD(var_r0, s16 *, 0xA6) > 6))) {
        M2C_FIELD(var_r0, s16 *, 0xA6) = 1;
        var_r0                         = (void *) (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 1);
        if (var_r0 != NULL) {
            var_r0 = (void *) func_020ac214(0);
        }
    }
    return (s32) var_r0;
}
