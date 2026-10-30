/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c75a0();                            /* extern */
M2C_UNK func_020c7640();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020c775c(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x22) == 0) {
        func_020c7640();
        return;
    }
    func_020c75a0();
}
