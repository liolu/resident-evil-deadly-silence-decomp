#include "m2c.h"
#include "engine.h"

void func_020c4798(M2C_UNK);

extern M2C_UNK data_0213b890;

void func_020c13f8(void) {
    M2C_FIELD(&data_0213b890, s8 *, 0x25) = 2;
    func_020c4798(4);
}
