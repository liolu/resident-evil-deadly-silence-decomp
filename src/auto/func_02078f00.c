/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02078c44();                            /* extern */
M2C_UNK func_02078d60(s32, s32, M2C_UNK);           /* extern */
extern M2C_UNK data_0211e864;

void func_02078f00(s32 arg0) {
    func_02078d60(((s32 *) &data_0211e864)[((s32) (arg0 & 0xF0) >> 4)], arg0, 0);
    func_02078c44();
}
