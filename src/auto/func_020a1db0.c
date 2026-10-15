#include "engine.h"
#include "m2c.h"

void func_020b82fc(M2C_UNK);

extern M2C_UNK data_0213ad98;

void func_020a1db0(void) {
    s32 var_r0;

    var_r0 = 7;
    if (M2C_FIELD(&data_0213ad98, u8 *, 0) == 4) {
        if (M2C_FIELD(&data_0213ad98, u8 *, 1) == 7) {
            var_r0 = 0x89;
        } else if (M2C_FIELD(&data_0213ad98, u8 *, 1) == 0xA) {
            var_r0 = 0x91;
        }
    }
    func_020b82fc(var_r0);
}
