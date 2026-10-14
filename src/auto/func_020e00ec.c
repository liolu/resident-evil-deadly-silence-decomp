#include "m2c.h"
#include "engine.h"

void func_020da480(M2C_UNK);

void func_020e00ec(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    func_020da480(M2C_FIELD(arg0, s32 *, 4));
}
