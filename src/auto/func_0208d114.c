#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02144bc0;

void func_0208d114(s32 arg0) {
    M2C_FIELD(&data_02144bc0, s16 *, 0xD8) = (s16) M2C_FIELD(arg0, s16 *, 0x94);
}
