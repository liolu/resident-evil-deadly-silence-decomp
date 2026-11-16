/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020ad9a8(s32); /* extern */
extern u16 data_0212c9cc[];
extern u8 data_0213bdcc[];

s16 func_0203043c(void) {
    u16 sp0[4];
    u16 *src;
    u16 *dst;
    u32 n;
    s32 temp_r0;
    s32 var_r4;

    src = data_0212c9cc;
    dst = sp0;
    n   = 4;
    do {
        *dst++ = *src++;
        n--;
    } while (n != 0);
    temp_r0 = *(s32 *) (data_0213bdcc + 0x48) & 0x20000;
    if (temp_r0 != 0) {
        var_r4 = 1;
    } else {
        var_r4 = 0;
    }
    return *(s16 *) ((u8 *) &sp0[var_r4 * 2] + (func_020ad9a8(temp_r0) * 2));
}
