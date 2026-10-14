#include "m2c.h"
#include "engine.h"

void func_020b82fc(M2C_UNK);

extern M2C_UNK data_0213ad98;

void func_020a1d74(void) {
    s32 var_r0;

    var_r0 = 9;
    if (M2C_FIELD(&data_0213ad98, u8 *, 0) == 4) {
        if (M2C_FIELD(&data_0213ad98, u8 *, 1) == 7) {
            var_r0 = 0x8B;
        } else if (M2C_FIELD(&data_0213ad98, u8 *, 1) == 0xA) {
            var_r0 = 0x93;
        }
    }
    func_020b82fc(var_r0);
}
