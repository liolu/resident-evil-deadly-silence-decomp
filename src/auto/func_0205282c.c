/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020520c0();                            /* extern */
s32 func_02075738(M2C_UNK, M2C_UNK);                /* extern */
extern void *data_027e000c;

void func_0205282c(void) {
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) != 0) {
        func_020520c0();
        M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    }
    M2C_FIELD(data_027e000c, s16 *, 0x42) = 0x4000;
    if (func_02075738(1, 0x200) != 0) {
        M2C_FIELD(data_027e000c, s8 *, 0xA)   = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x91)  = 0;
        M2C_FIELD(data_027e000c, s16 *, 0x42) = 0;
    }
}
