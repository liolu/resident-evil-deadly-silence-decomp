/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02078c44();                            /* extern */
M2C_UNK func_02079174();                            /* extern */
M2C_UNK func_020c46c8(u8, M2C_UNK);                 /* extern */
extern M2C_UNK data_0213b890;

void func_020d5748(void) {
    M2C_FIELD(&data_0213b890, s8 *, 0x50) = 3;
    func_02079174();
    func_02078c44();
    func_020c46c8(M2C_FIELD(&data_0213b890, u8 *, 0x24), 0);
}
