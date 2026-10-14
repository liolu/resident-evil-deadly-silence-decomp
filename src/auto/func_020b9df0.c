#include "m2c.h"
#include "engine.h"

void func_020b3a24(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213be00;

void func_020b9df0(void) {
    M2C_FIELD(&data_0213b890, s8 *, 0x278) = 2;
    func_020b3a24((s32) &data_0213be00, 0x16);
}
