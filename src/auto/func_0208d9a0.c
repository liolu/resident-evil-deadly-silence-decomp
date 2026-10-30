/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02090744(M2C_UNK);                     /* extern */
extern void *data_0213789c;
extern M2C_UNK data_0213ad3c;
extern M2C_UNK data_0213ae4c;

void func_0208d9a0(void) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(data_0213789c, u16 *, 0xA);
    if (temp_r0 != 0) {
        M2C_FIELD(data_0213789c, u16 *, 0xA) = (u16) (temp_r0 - 1);
        return;
    }
    if ((M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x30) || (M2C_FIELD(&data_0213ae4c, u8 *, 2) != 0)) {
        func_0206fcf8(3, 1, 1, 0x80);
        func_02090744(0);
        M2C_FIELD(data_0213789c, u8 *, 4) = (u8) (M2C_FIELD(data_0213789c, u8 *, 4) + 1);
    }
}
