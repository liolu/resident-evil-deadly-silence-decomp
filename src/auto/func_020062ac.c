#include "engine.h"
#include "m2c.h"

void func_020061f4(M2C_UNK);

void func_020062ac(s32 arg0, s32 arg1) {
    M2C_FIELD(arg1, s8 *, 0xA) = 0;
    func_020061f4(arg0);
}
