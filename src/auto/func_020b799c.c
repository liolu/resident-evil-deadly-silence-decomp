/* compiler: 1.2/sp3 -O2,p */
#include "m2c.h"

extern M2C_UNK data_0213abc4;

u8 func_020b799c(void) {
    u32 i;
    u32 cnt;
    u8 t;

    cnt = 0;
    i   = 0;
loop:
    t = M2C_FIELD(((i * 0xC) + (s32) &data_0213abc4), u8 *, 0xE5);
    i += 1;
    if (t != 0) {
        cnt += 1;
    }
    if (i < 4) {
        goto loop;
    }
    return (u8) cnt;
}
