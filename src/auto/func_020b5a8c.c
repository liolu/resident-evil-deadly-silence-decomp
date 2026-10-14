#include "m2c.h"

extern void *data_027e000c;

s32 func_020b5a8c(void) {
    M2C_FIELD(data_027e000c, u8 *, 0xC0) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xC0) | 8);
    return 1;
}
