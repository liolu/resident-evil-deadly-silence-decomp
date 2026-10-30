/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffb948(M2C_UNK *, M2C_UNK *, M2C_UNK);   /* extern */
extern M2C_UNK data_027e0028;
extern M2C_UNK data_027e0054;

void func_02017a94(void *arg0) {
    M2C_FIELD(&data_027e0054, s32 *, 0) = (s32) M2C_FIELD(arg0, s16 *, 0x20);
    M2C_FIELD(&data_027e0054, s32 *, 4) = (s32) M2C_FIELD(arg0, s16 *, 0x22);
    M2C_FIELD(&data_027e0054, s32 *, 8) = (s32) M2C_FIELD(arg0, s16 *, 0x24);
    M2C_FIELD(&data_027e0028, s16 *, 0) = 0;
    M2C_FIELD(&data_027e0028, s16 *, 2) = 0;
    M2C_FIELD(&data_027e0028, s16 *, 4) = 0;
    if (func_01ffb948(&data_027e0054, &data_027e0028, 4) != 0) {
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
        M2C_FIELD(arg0, s16 *, 0x12) = 0;
        M2C_FIELD(arg0, s16 *, 0x14) = 0;
        M2C_FIELD(arg0, s8 *, 0)     = 1;
    }
}
