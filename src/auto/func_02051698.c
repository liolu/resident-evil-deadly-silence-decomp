/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02051218();                            /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern void *data_027e000c;

void func_02051698(void) {
    func_02051218();
    func_02075738(1, 0x200);
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0xA)  = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) | 0x20);
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
    }
}
