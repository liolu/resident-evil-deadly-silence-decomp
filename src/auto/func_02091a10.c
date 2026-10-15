#include "engine.h"
#include "m2c.h"

void func_02091a10(s32 arg0) {
    s32 temp_r1;
    s32 temp_r1_2;
    s32 temp_r1_3;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r1_3;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_r1 >= 0) {
        var_r1 = temp_r1 + 0x800;
    } else {
        var_r1 = temp_r1 - 0x800;
    }
    M2C_FIELD(arg0, s32 *, 0) = (s32) (var_r1 >> 0xC);
    temp_r1_2                 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r1_2 >= 0) {
        var_r1_2 = temp_r1_2 + 0x800;
    } else {
        var_r1_2 = temp_r1_2 - 0x800;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (var_r1_2 >> 0xC);
    temp_r1_3                 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_r1_3 >= 0) {
        var_r1_3 = temp_r1_3 + 0x800;
    } else {
        var_r1_3 = temp_r1_3 - 0x800;
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (var_r1_3 >> 0xC);
}
