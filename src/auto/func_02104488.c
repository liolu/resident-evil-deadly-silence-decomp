#include "engine.h"
#include "m2c.h"

void func_02104488(s32 arg0, s32 arg1) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg1, void **, 0x10);
    temp_r1 = M2C_FIELD(arg1, void **, 0xC);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, void **, 0x80) = temp_r1;
    } else {
        M2C_FIELD(temp_r2, void **, 0xC) = temp_r1;
    }
    if (temp_r1 == NULL) {
        M2C_FIELD(arg0, void **, 0x7C) = temp_r2;
        return;
    }
    M2C_FIELD(temp_r1, void **, 0x10) = temp_r2;
}
