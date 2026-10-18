/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020b842c(M2C_UNK, u16);                /* extern */
extern M2C_UNK data_02123630;
extern M2C_UNK data_02147cc0;

void func_020b6e58(void) {
    func_020b842c(0, (u16) ((s8 *) &data_02123630)[*M2C_FIELD(&data_02147cc0, u8 **, 0x53C)]);
}
