#include "engine.h"
#include "m2c.h"

extern u8 data_0213ad84;

void func_020727e8(s32 arg0) {
    if (data_0213ad84 == 0) {
        *(M2C_UNK *) arg0 = 6;
    }
}
