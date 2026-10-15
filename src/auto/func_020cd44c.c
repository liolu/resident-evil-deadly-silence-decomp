#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213ba90;

void func_020cd44c(void) {
    M2C_FIELD(&data_0213ba90, s16 *, 0x6C) =
        (s16) ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 4) >> 0x10);
}
