/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02001404(M2C_UNK);                         /* extern */
M2C_UNK func_02015ce0(void *);                      /* extern */
M2C_UNK func_02016b08(void *);                      /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_027e0054;

void func_020163a0(void *arg0) {
    u8 temp_r4;

    temp_r4                                = M2C_FIELD(&data_02143cc0, u8 *, 0xF4C);
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(&data_027e0054, s32 *, 0)    = (s32) M2C_FIELD(arg0, s16 *, 0x20);
    M2C_FIELD(&data_027e0054, s32 *, 8)    = (s32) M2C_FIELD(arg0, s16 *, 0x24);
    if (func_02001404(6) != 0) {
        func_02016b08(arg0);
        func_02015ce0(arg0);
    }
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = temp_r4;
}
