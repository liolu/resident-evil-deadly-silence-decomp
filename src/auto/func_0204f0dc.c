/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020ad9a8();                                /* extern */
M2C_UNK func_020b81e4(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_020b8210(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;

void func_0204f0dc(void) {
    if (func_020ad9a8() != 0) {
        if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) != 3) {
            func_020b8210(5, 0x7C, &data_02144c34, 0);
            return;
        }
        func_020b81e4(0x2C, &data_02144c34, 0);
        return;
    }
    func_020b8210(5, 0x7B, &data_02144c34, 0);
}
