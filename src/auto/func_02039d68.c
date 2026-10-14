/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020182bc(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32); /* extern */
M2C_UNK func_0209fbf0();                            /* extern */
extern s32 data_027e000c;
extern M2C_UNK data_027e0054;
extern M2C_UNK data_027e009c;

void func_02039d68(s32 arg0) {
    M2C_FIELD(&data_027e0054, s32 *, 8) = 0;
    M2C_FIELD(&data_027e0054, s32 *, 4) = 0;
    M2C_FIELD(&data_027e0054, s32 *, 0) = 0;
    func_0209fbf0(arg0);
    func_020182bc(data_027e000c, 3, 0, 0, &data_027e009c, &data_027e0054, 0);
}
