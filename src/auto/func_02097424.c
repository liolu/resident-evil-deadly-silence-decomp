/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s8 *data_02137ed8;
extern M2C_UNK data_0213ad3c;
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_0213b890;

void func_02097424(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x24) == 0) {
        if ((M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x30) || (M2C_FIELD(&data_0213ae4c, u8 *, 2) != 0)) {
            func_0206fcf8(0, 2, 1, 0x100);
            *data_02137ed8 = 2;
        }
    } else {
        M2C_FIELD(&data_0213b890, u8 *, 0x24) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x24) - 1);
    }
}
