/* compiler: 1.2/sp2p3 */
#include "m2c.h"

u64 func_0211851c(u32, M2C_UNK);

u8 func_0200e9d4(u8 *arg0, u32 arg1) {
    u64 r;
    s32 sh;
    u8 b;

    r  = func_0211851c(arg1, 8);
    sh = (u32) (r >> 32);
    b  = arg0[arg1 >> 3];
    return (u8) (((s32) b >> sh) & 1);
}
