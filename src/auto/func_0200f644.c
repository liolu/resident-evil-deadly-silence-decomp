/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200ea9c();                            /* extern */
M2C_UNK func_0200f208();                            /* extern */
M2C_UNK func_02017c18();                            /* extern */
s32 func_020709dc(M2C_UNK);                         /* extern */
extern M2C_UNK data_02143cc0;

void func_0200f644(void) {
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xE) == 0) {
        if (func_020709dc(1) != 0) {
            M2C_FIELD(&data_02143cc0, s8 *, 0xF) = 1;
        }
        return;
    }
    func_02017c18();
    func_0200f208();
    func_0200ea9c();
}
