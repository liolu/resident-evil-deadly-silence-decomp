/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffb948(M2C_UNK *, M2C_UNK *, M2C_UNK);   /* extern */
M2C_UNK func_020ac168();                            /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_027e0028;
extern M2C_UNK data_027e0054;

void func_0201794c(void *arg0) {
    M2C_FIELD(&data_027e0054, volatile s32 *, 0) = (s32) M2C_FIELD(arg0, volatile s16 *, 0x20);
    M2C_FIELD(&data_027e0054, volatile s32 *, 4) = (s32) M2C_FIELD(arg0, volatile s16 *, 0x22);
    M2C_FIELD(&data_027e0054, volatile s32 *, 8) = (s32) M2C_FIELD(arg0, volatile s16 *, 0x24);
    M2C_FIELD(&data_027e0028, volatile s16 *, 0) = 0;
    M2C_FIELD(&data_027e0028, volatile s16 *, 2) = 0;
    M2C_FIELD(&data_027e0028, volatile s16 *, 4) = 0;
    if (func_01ffb948(&data_027e0054, &data_027e0028, 4) != 0) {
        M2C_FIELD(arg0, volatile s8 *, 0)     = 1;
        M2C_FIELD(arg0, volatile s8 *, 4)     = 2;
        M2C_FIELD(arg0, volatile s8 *, 6)     = 1;
        M2C_FIELD(arg0, volatile s16 *, 0x10) = (s16) (M2C_FIELD(arg0, volatile s16 *, 0x10) * -1);
        if ((M2C_FIELD(&data_02143cc0, volatile u8 *, 0xF4E) - 2) == M2C_FIELD(arg0, volatile u8 *, 7)) {
            M2C_FIELD(&data_027e0054, volatile s32 *, 0) = (s32) M2C_FIELD(arg0, volatile s16 *, 0x20);
            M2C_FIELD(&data_027e0054, volatile s32 *, 4) = (s32) M2C_FIELD(arg0, volatile s16 *, 0x22);
            M2C_FIELD(&data_027e0054, volatile s32 *, 8) = (s32) M2C_FIELD(arg0, volatile s16 *, 0x24);
            func_020ac168();
        }
    }
}
