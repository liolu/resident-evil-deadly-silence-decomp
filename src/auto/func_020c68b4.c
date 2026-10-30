/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c6470();                            /* extern */
M2C_UNK func_020c6794();                            /* extern */
M2C_UNK func_020c8a80();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020c68b4(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x21) == 0) {
        func_020c6794();
        func_020c8a80();
        return;
    }
    func_020c6470();
}
