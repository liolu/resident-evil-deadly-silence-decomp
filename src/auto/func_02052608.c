/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02075738(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
extern void *data_027e000c;

void func_02052608(void) {
    if (func_02075738(1, 0x200) != 0) {
        M2C_FIELD(data_027e000c, u8 *, 0xA) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) | 0x20);
    }
    if (M2C_FIELD(data_027e000c, u8 *, 0xA2) == 9) {
        func_020b82fc(0x80);
    }
}
