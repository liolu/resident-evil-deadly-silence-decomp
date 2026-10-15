/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_020ec950(M2C_UNK, M2C_UNK);

s32 func_020e9758(s32 arg0, s32 arg1) {
    s32 var_r1;

    M2C_FIELD(arg1, s32 *, 0) = func_020ec950(arg0, 1);
    M2C_FIELD(arg1, s32 *, 4) = (s32) (4 - func_020ec950(arg0, 2));
    if (func_020ec950(arg0, 1) == 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    M2C_FIELD(arg1, s32 *, 8)    = var_r1;
    M2C_FIELD(arg1, s32 *, 0xC)  = func_020ec950(arg0, 4);
    M2C_FIELD(arg1, s32 *, 0x10) = func_020ec950(arg0, 2);
    M2C_FIELD(arg1, s32 *, 0x14) = func_020ec950(arg0, 1);
    M2C_FIELD(arg1, s32 *, 0x18) = func_020ec950(arg0, 1);
    M2C_FIELD(arg1, s32 *, 0x1C) = func_020ec950(arg0, 2);
    M2C_FIELD(arg1, s32 *, 0x20) = func_020ec950(arg0, 2);
    M2C_FIELD(arg1, s32 *, 0x24) = func_020ec950(arg0, 1);
    M2C_FIELD(arg1, s32 *, 0x28) = func_020ec950(arg0, 1);
    M2C_FIELD(arg1, s32 *, 0x2C) = func_020ec950(arg0, 2);
    if ((M2C_FIELD(arg1, s32 *, 0x1C) != 3) || (M2C_FIELD(arg1, s32 *, 0x20) != 0)) {
        return -1;
    }
    return 0;
}
