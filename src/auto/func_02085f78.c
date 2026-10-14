#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021374cc;

void func_02085f78(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(&data_021374cc, s16 *, 0x32) = (s16) arg0;
        return;
    }
    M2C_FIELD(&data_021374cc, s16 *, 0x30) = (s16) arg0;
}
