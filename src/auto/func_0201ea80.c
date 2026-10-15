#include "engine.h"
#include "m2c.h"

void func_0201ea80(s32 arg0, s32 arg1, s32 arg2) {
    s16 temp_r3;

    temp_r3 = M2C_FIELD(arg0, s16 *, 0xA6);
    if ((s32) temp_r3 <= arg2) {
        return;
    }
    M2C_FIELD(arg0, s16 *, 0xA6) = (s16) (temp_r3 - arg1);
    if ((s32) M2C_FIELD(arg0, s16 *, 0xA6) < arg2) {
        M2C_FIELD(arg0, s16 *, 0xA6) = (s16) arg2;
    }
}
