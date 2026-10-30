/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200d8b4(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_0200d958(s32, M2C_UNK);                /* extern */
s32 func_020b86e8();                                /* extern */
extern M2C_UNK data_0213ac4c;

void func_020b8524(s32 arg0) {
    s32 temp_r0;

    func_0200d958(arg0, 8);
    temp_r0                                             = func_020b86e8();
    *((M2C_UNK *) ((s8 *) &data_0213ac4c + (arg0 * 4))) = temp_r0;
    if (temp_r0 != 0) {
        func_0200d8b4(arg0, temp_r0, 8);
    }
}
