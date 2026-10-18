/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b8310(u8);                          /* extern */
extern M2C_UNK data_0211bc32;
extern void *data_0213ad2c;

void func_020127ac(void *arg0, void *arg1) {
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (M2C_FIELD(arg1, u8 *, 0xE4) - 1);
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0x46) {
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc32 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
    }
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0x14) {
        func_0206fcf8(0, 1, 1, 0x100);
    }
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0) {
        M2C_FIELD(arg0, s8 *, 4) = 2;
    }
}
