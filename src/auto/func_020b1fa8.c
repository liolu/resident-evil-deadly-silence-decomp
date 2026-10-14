#include "m2c.h"

extern M2C_UNK data_02144c04;

s32 func_020b1fa8(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, M2C_UNK **, 4) = &data_02144c04;
    return 0;
}
