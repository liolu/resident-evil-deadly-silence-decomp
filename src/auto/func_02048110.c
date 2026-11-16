/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0212cb74[];

s8 func_02048110(s32 arg0) {
    u8 buf[8];
    u8 *src;
    u8 *dst;
    u32 n;
    u8 c;

    src = data_0212cb74;
    dst = buf;
    n   = 5U;
    do {
        c = *src;
        src++;
        n--;
        *dst = c;
        dst++;
    } while (n != 0);
    return (s8) buf[arg0];
}
