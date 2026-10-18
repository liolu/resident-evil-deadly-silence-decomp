/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020c46d4();                            /* extern */
extern M2C_UNK data_0212561a;
extern M2C_UNK data_0213b890;
extern M2C_UNK func_020c45b0;

void func_020c4614(void) {
    func_020c46d4();
    M2C_FIELD(&data_0213b890, s8 *, 0x20)       = 0;
    M2C_FIELD(&data_0213b890, M2C_UNK **, 0x40) = &func_020c45b0;
    if (*((u8 *) ((s8 *) &data_0212561a + (M2C_FIELD(&data_0213b890, u8 *, 0x38) * 8))) != 0) {
        func_0206fcf8(1, 1, 1, 0x100);
    }
    if (*((u8 *) ((s8 *) &data_0212561a + (M2C_FIELD(&data_0213b890, u8 *, 0x16) * 8))) != 0) {
        func_0206fcf8(1, 1, 1, 0x100);
    }
    func_0206fcf8(0, 1, 1, 0x100);
}
