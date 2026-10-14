/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_021041b8();                                /* extern */
M2C_UNK func_02104800(M2C_UNK, s32);                /* extern */
M2C_UNK func_02104814(M2C_UNK, s32);                /* extern */
s32 func_02104828(M2C_UNK);                         /* extern */
s32 func_02104910(M2C_UNK);                         /* extern */
M2C_UNK func_02104c30(s32);                         /* extern */
M2C_UNK func_02104c38(s32);                         /* extern */
extern s32 data_02158adc;

void func_02104a64(void) {
    func_02104814(2, func_02104910(2));
    func_02104800(2, func_02104828(2));
    if ((data_02158adc != 0) && ((func_021041b8() & 3) != 1)) {
        return;
    }
    func_02104c30(0x0200002B);
    func_02104c38(0x023E0021);
}
