#include "engine.h"
#include "m2c.h"

void func_020da428(M2C_UNK, M2C_UNK);

void func_020e00d8(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x38) = arg1;
    func_020da428(M2C_FIELD(arg0, s32 *, 4), arg1);
}
