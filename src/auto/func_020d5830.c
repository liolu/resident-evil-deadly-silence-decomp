#include "m2c.h"
#include "engine.h"

void func_020c4798(M2C_UNK);

extern M2C_UNK data_0213b890;

void func_020d5830(s32 arg0) {
    M2C_FIELD(&data_0213b890, s8 *, 0x24) = (s8) arg0;
    func_020c4798(3);
}
