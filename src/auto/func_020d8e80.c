#include "m2c.h"
#include "engine.h"

void func_020d6b14(M2C_UNK);

extern M2C_UNK data_0213caa0;

void func_020d8e80(void) {
    M2C_FIELD(&data_0213caa0, s8 *, 0x709) = 0;
    func_020d6b14(0);
}
