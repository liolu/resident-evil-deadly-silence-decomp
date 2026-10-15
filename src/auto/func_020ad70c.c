#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02144bc0;

void func_020ad70c(s32 arg0) {
    M2C_FIELD(&data_02144bc0, s16 *, 0xD8) = (s16) arg0;
}
