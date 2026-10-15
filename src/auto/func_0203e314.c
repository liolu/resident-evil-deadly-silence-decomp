/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020182bc(void *, M2C_UNK, M2C_UNK, s32, M2C_UNK *, M2C_UNK *, s32); /* extern */
M2C_UNK func_0209fbf0(s16);                         /* extern */
extern M2C_UNK data_02144bc0;
extern void *data_027e000c;
extern M2C_UNK data_027e0054;
extern M2C_UNK data_027e009c;

void func_0203e314(s16 arg0, M2C_UNK arg1) {
    M2C_FIELD(data_027e000c, s16 *, 0x190) = arg0;
    func_0209fbf0(M2C_FIELD(data_027e000c, s16 *, 0x190));
    func_020182bc(data_027e000c, 0, arg1,
                  (M2C_FIELD(&data_02144bc0, s16 *, 0x88) - M2C_FIELD(data_027e000c, s16 *, 0x44)) + 0x800, &data_027e009c,
                  &data_027e0054, 0);
}
