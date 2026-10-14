/* compiler: 1.2/sp2p3  */
#include "m2c.h"

u32 func_02005ed8(s32, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_02006358(s32, s32, M2C_UNK, u8);       /* extern */
M2C_UNK func_02006390();                            /* extern */
s32 func_02070088(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0213ade4;

s32 func_02005f54(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_r0;

    func_02006390();
    temp_r0 = func_02070088(&data_0213ade4, 3, arg1, 1);
    if (temp_r0 != 0) {
        func_02006358(arg0, temp_r0, arg3, (u8) (func_02005ed8((arg0 >> 7) & 1, arg3, arg2) >> 5));
    }
    return arg0;
}
