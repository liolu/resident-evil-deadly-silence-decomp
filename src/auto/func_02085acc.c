/* compiler: 2.0/sp1p5 -O1 */
#include "m2c.h"

s32 func_02085acc(void *arg0) {
    u8 a;
    u8 b;

    a = M2C_FIELD(arg0, u8 *, 0xA);
    b = M2C_FIELD(arg0, u8 *, 0xB);
    return b + (a << 2);
}
