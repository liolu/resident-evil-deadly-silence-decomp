/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02005e44(M2C_UNK, s32, M2C_UNK, s32);  /* extern */
M2C_UNK func_020064dc(M2C_UNK, M2C_UNK);            /* extern */
s32 func_02070088(M2C_UNK *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK func_02070438(s32);                         /* extern */
extern M2C_UNK data_0213ad74;
extern M2C_UNK data_0213ade4;

s32 func_02005ed8(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    s32 temp_r0;
    s32 var_r5;

    var_r5 = 0;
    if (arg2 != 0) {
        temp_r0 = func_02070088(&data_0213ade4, 1, arg2, 1);
        if (temp_r0 != 0) {
            var_r5 = M2C_FIELD(&data_0213ad74, s32 *, 0xC);
            func_02005e44(arg0, temp_r0, arg1, var_r5);
            func_02070438(temp_r0);
            func_020064dc(arg0, 1);
        }
    }
    return var_r5;
}
