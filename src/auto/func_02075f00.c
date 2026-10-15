/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020f3de4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020f4010(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_020f8758(M2C_UNK);

void func_02075f00(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r4;
    s32 var_r5;

    var_r5                       = arg2;
    M2C_FIELD(arg0, s16 *, 2)    = (s16) var_r5;
    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r4                      = func_020f8758(M2C_FIELD(M2C_FIELD(arg1, void **, 4), s32 *, 4));
    if (var_r5 == 0xFF) {
        func_020f4010(M2C_FIELD(arg0, s32 *, 0xC), temp_r4, 0, 0);
        func_020f3de4(M2C_FIELD(arg0, s32 *, 0xC), temp_r4, 0, 0);
        var_r5 = 1;
    }
    func_020f4010(M2C_FIELD(arg0, s32 *, 0xC), temp_r4, var_r5, var_r5);
    func_020f3de4(M2C_FIELD(arg0, s32 *, 0xC), temp_r4, var_r5, var_r5);
}
