#include "m2c.h"

M2C_UNK func_020539bc();                            /* extern */
extern M2C_UNK data_02144cc0;

void func_02053a74(s32 arg0) {
    M2C_FIELD(&data_02144cc0, s8 *, 0xE6) = 0;
    func_020539bc(arg0);
}
