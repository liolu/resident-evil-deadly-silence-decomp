#include "engine.h"
#include "m2c.h"

void func_02014c54(M2C_UNK);

void func_02014cf0(s32 arg0) {
    M2C_FIELD(arg0, void (**)(s32), 0x14) = func_02014c54;
    M2C_FIELD(arg0, s8 *, 0x8E)           = 2;
}
