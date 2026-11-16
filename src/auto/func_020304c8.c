/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u16 data_0212ca04[];
s32 func_020b6b5c(void);
void func_020b8110();

void func_020304c8(s32 arg0, s32 arg1) {
    u16 buf[16];
    u16 *src;
    u16 *dst;
    u32 n;
    s32 sel;

    src = data_0212ca04;
    dst = buf;
    n   = 16;
    do {
        *dst++ = *src++;
    } while (--n != 0);
    if (func_020b6b5c() != 0) {
        sel = 1;
    } else {
        sel = 0;
    }
    func_020b8110(*(u16 *) ((u8 *) buf + arg0 * 4 + sel * 2), (s16) (arg1 * 0x64));
}
