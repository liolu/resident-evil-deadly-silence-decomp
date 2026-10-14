#include "m2c.h"
#include "engine.h"

s32 func_020ed194(s32 arg0) {
    s32 temp_r2;

    temp_r2 = *(M2C_UNK *)arg0;
    if (temp_r2 == 1) {
        *(M2C_UNK *)arg0 = 2;
    }
    return temp_r2;
}
