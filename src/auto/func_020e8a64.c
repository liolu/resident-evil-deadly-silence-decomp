#include "m2c.h"

extern s32 data_02154010;

s32 func_020e8a64(s32 arg0) {
    s32 temp_r2;

    temp_r2       = data_02154010;
    data_02154010 = arg0;
    return temp_r2;
}
