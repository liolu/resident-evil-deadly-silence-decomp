/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e40e4(M2C_UNK, M2C_UNK);

extern M2C_UNK data_02130308;
extern M2C_UNK data_02130314;
extern M2C_UNK data_02130330;
extern M2C_UNK data_0213033c;

s32 func_020e3498(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK (*temp_r2)(s32, M2C_UNK);
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_r4;

    if (arg0 == 0) {
        func_020e40e4((s32) &data_02130308, (s32) &data_02130314);
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 4) == 0) {
        func_020e40e4((s32) &data_02130330, (s32) &data_0213033c);
        return 0;
    }
    if (arg1 == 0) {
        var_r4 = M2C_FIELD(arg0, s32 *, 0x10);
        temp_r0 = M2C_FIELD(arg0, s32 *, 0x24) + (M2C_FIELD(arg0, s32 *, 0x20) - M2C_FIELD(arg0, s32 *, 0x14));
        if (var_r4 >= temp_r0) {
            var_r4 = temp_r0;
        }
        if (var_r4 >= arg2) {
            var_r4 = arg2;
        }
    } else if (arg1 == 1) {
        var_r4 = M2C_FIELD(arg0, s32 *, 0xC);
        temp_r0_2 = M2C_FIELD(arg0, s32 *, 0x24) + (M2C_FIELD(arg0, s32 *, 0x20) - M2C_FIELD(arg0, s32 *, 0x18));
        if (var_r4 >= temp_r0_2) {
            var_r4 = temp_r0_2;
        }
        if (var_r4 >= arg2) {
            var_r4 = arg2;
        }
    } else {
        temp_r2 = M2C_FIELD(arg0, M2C_UNK (**)(s32, M2C_UNK), 0x38);
        var_r4 = 0;
        if (temp_r2 != NULL) {
            temp_r2(M2C_FIELD(arg0, s32 *, 0x3C), -3);
        }
    }
    *(M2C_UNK *)arg3 = var_r4;
    if (var_r4 == arg2) {
        return 1;
    }
    return 0;
}
