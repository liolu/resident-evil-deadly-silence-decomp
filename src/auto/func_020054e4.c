/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020ed908(void *);                          /* extern */
u32 func_020ed920(void *);                          /* extern */
M2C_UNK func_02105528();                            /* extern */
extern void *data_02137264;

void func_020054e4(void) {
    if (M2C_FIELD(data_02137264, s32 *, 0x53C) == 0) {
        M2C_FIELD(data_02137264, s32 *, 0x560) = 4;
        if (func_020ed920(data_02137264 + 0x550) > 0x68000U) {
            func_02105528();
        }
        M2C_FIELD(data_02137264, void **, 0x568) = (void *) (data_02137264 + 0x20F64);
        M2C_FIELD(data_02137264, s32 *, 0x53C)   = func_020ed908(data_02137264 + 0x550);
    }
}
