#include "m2c.h"
#include "engine.h"

void func_021044ac(s32 arg0, s32 arg1) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0x80);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
    } else {
        M2C_FIELD(temp_r2, s32 *, 0x10) = arg1;
    }
    M2C_FIELD(arg1, void **, 0xC) = temp_r2;
    M2C_FIELD(arg1, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, void **, 0x80) = (void *) arg1;
}
