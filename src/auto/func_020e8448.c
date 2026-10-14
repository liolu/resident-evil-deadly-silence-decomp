/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e84f0(s32);                         /* extern */
s32 func_020e855c();                                /* extern */
M2C_UNK func_020e8720(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_02112754(s32, s32);                    /* extern */
extern M2C_UNK data_021312f4;
extern M2C_UNK data_02131318;
extern M2C_UNK data_0213133c;

s32 func_020e8448(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;

    if (arg0 == 0) {
        func_020e8720(0, &data_021312f4);
        return 0;
    }
    if (arg2 != 0) {
        func_020e8720(0, &data_02131318);
        return 0;
    }
    temp_r0 = func_020e855c();
    if (temp_r0 == 0) {
        func_020e8720(0, &data_0213133c);
        return 0;
    }
    func_02112754(temp_r0 + 0x1C, arg0);
    func_020e84f0(temp_r0);
    return temp_r0;
}
