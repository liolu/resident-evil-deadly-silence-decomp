/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffb948(M2C_UNK *, M2C_UNK *, M2C_UNK);   /* extern */
M2C_UNK func_02015ce0(void *);                      /* extern */
M2C_UNK func_02016b08(void *);                      /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_027e0028;
extern M2C_UNK data_027e0054;

void func_02016838(void *arg0) {
    u8 temp_r4;

    M2C_FIELD(&data_027e0028, s16 *, 0)    = 0;
    M2C_FIELD(&data_027e0028, s16 *, 2)    = 0;
    M2C_FIELD(&data_027e0028, s16 *, 4)    = 0;
    M2C_FIELD(&data_027e0054, s32 *, 0)    = (s32) M2C_FIELD(arg0, s16 *, 0x20);
    temp_r4                                = M2C_FIELD(&data_02143cc0, u8 *, 0xF4C);
    M2C_FIELD(&data_027e0054, s32 *, 4)    = (s32) M2C_FIELD(arg0, s16 *, 0x22);
    M2C_FIELD(&data_027e0054, s32 *, 8)    = (s32) M2C_FIELD(arg0, s16 *, 0x24);
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) M2C_FIELD(arg0, u8 *, 6);
    if ((func_01ffb948(&data_027e0054, &data_027e0028, 4) != 0) && (M2C_FIELD(arg0, u8 *, 6) == 0x21)) {
        func_02016b08(arg0);
        func_02015ce0(arg0);
        M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = temp_r4;
        return;
    }
    if (func_01ffb948(&data_027e0054, &data_027e0028, 4) == 1) {
        func_02016b08(arg0);
        func_02015ce0(arg0);
    }
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = temp_r4;
}
