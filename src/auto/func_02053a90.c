#include "m2c.h"

extern M2C_UNK data_02143cc0;

u32 func_02053a90(void) {
    u32 i;
    u8 *base;

    i    = 0x11;
    base = (u8 *) &data_02143cc0;
    goto check;
loop:
    if (*(base + i * 4 + 0x447C) == 0) {
        return i;
    }
    i = (u8) (i + 1);
check:
    if (i <= 0x2EU) {
        goto loop;
    }
    return 0;
}
