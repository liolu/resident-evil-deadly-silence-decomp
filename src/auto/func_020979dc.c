/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02003a0c(M2C_UNK);                     /* extern */
M2C_UNK func_0209f5a8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s32 data_02137ed8;

void func_020979dc(s32 arg0) {
    func_02003a0c(0);
    func_02003a0c(1);
    func_02003a0c(2);
    func_02003a0c(3);
    func_0209f5a8(data_02137ed8 + 0x39C, 0, 2);
    if (arg0 != 1) {
        func_0209f5a8(data_02137ed8 + 0x13F8, 1, 2);
    }
}
