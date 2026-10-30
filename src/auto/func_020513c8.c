/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02051218();                            /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_02143cc0;
extern void *data_027e000c;

void func_020513c8(void) {
    func_02075738(1, 0x80);
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 1) {
        if ((u32) M2C_FIELD(data_027e000c, u8 *, 0xA2) > 5U) {
            M2C_FIELD(data_027e000c, u8 *, 0xA2) = 5U;
        }
    } else {
        M2C_FIELD(data_027e000c, u8 *, 0xA2) = 0x28U;
    }
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
        return;
    }
    func_02051218();
}
