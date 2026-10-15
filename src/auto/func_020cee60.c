#include "engine.h"
#include "m2c.h"

void func_02076e50(M2C_UNK);

extern M2C_UNK data_0213b890;

void func_020cee60(void) {
    func_02076e50(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0xD8);
}
