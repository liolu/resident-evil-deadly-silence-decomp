#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020d1f7c(s32 arg0) {
    s16 var_r1;

    switch (arg0) {                                 /* irregular */
        case 1:
            var_r1 = 0xD0;
            break;
        case 2:
            var_r1 = 0xD7;
            break;
        default:
        case 0:
            var_r1 = 0;
            break;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0xF0) = var_r1;
}
