/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c46b4(M2C_UNK);                     /* extern */
M2C_UNK func_020d5298();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020cab28(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x1F) != 0) {
        func_020d5298();
        return;
    }
    func_020c46b4(0);
}
