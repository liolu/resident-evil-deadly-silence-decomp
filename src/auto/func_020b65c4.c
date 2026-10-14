#include "m2c.h"
#include "engine.h"

void func_020b6570(M2C_UNK);

extern M2C_UNK data_0213af7c;

void func_020b65c4(void) {
    M2C_FIELD(&data_0213af7c, u16 *, 0x1E) = (u16) ((s32) M2C_FIELD(&data_0213af7c, u16 *, 0x1E) >> 8);
    func_020b6570((s32) M2C_FIELD(&data_0213af7c, u16 *, 0x1E));
}
