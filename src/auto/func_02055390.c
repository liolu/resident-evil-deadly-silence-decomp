/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef s32 (*Handler)(void);
extern Handler data_0211cff0[];
extern void *data_027e000c;

s32 func_02055390(void) {
    s32 var_r0;

    data_0211cff0[M2C_FIELD(data_027e000c, u8 *, 0x92)]();
    var_r0 = M2C_FIELD(data_027e000c, u16 *, 0xEC) & 2;
    if (var_r0 != 0) {
        var_r0 = data_0211cff0[M2C_FIELD(data_027e000c, u8 *, 0x92)]();
    }
    return var_r0;
}
