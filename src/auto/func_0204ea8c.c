/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b3864(void *);                      /* extern */
extern void *data_027e000c;

void func_0204ea8c(void) {
    M2C_FIELD(data_027e000c, s16 *, 0x17E) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x17E) - 0x70);
    M2C_FIELD(data_027e000c, s16 *, 0xA8)  = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) + 1);
    if (!(M2C_FIELD(data_027e000c, s16 *, 0xA8) & 3)) {
        M2C_FIELD(data_027e000c, s16 *, 0x18E) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x18E) + 1);
    }
    if ((s32) M2C_FIELD(data_027e000c, s16 *, 0x17E) <= 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
        func_020b3864(data_027e000c);
    }
}
