/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0202bb84(u8);                          /* extern */
M2C_UNK func_02090b70(M2C_UNK *, M2C_UNK);          /* extern */
s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
extern void *data_02137338;
extern M2C_UNK data_02144c04;
extern void *data_027e000c;

void func_0202e024(void) {
    if ((func_0209109c(0, 0x400, 7) != 0) || ((u32) M2C_FIELD(data_027e000c, u8 *, 0xA2) >= 0x2DU)) {
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 7;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
    }
    func_02090b70(&data_02144c04, 1);
    func_0202bb84((u8) M2C_FIELD(data_02137338, u16 *, 0xE));
}
