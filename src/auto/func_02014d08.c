#include "engine.h"
#include "m2c.h"

void func_02014cf0(M2C_UNK);
void func_020f437c(M2C_UNK, M2C_UNK);

void func_02014d08(s32 arg0) {
    func_020f437c(*(M2C_UNK *) arg0 + 0x20, (s32) func_02014cf0);
}
