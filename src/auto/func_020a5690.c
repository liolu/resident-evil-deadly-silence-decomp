/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020ad9a8();                                /* extern */
extern M2C_UNK data_02121950;

void func_020a5690(void *arg0) {
    s32 temp_r0;
    s32 temp_r1;

    if (M2C_FIELD(arg0, u8 *, 0xB) & 0x10) {
        M2C_FIELD(arg0, s32 *, 0x34) =
            (s32) (M2C_FIELD(arg0, s32 *, 0x34) + *(s8 *) ((u8 *) &data_02121950 + func_020ad9a8()));
        return;
    }
    temp_r0                      = func_020ad9a8() + 2;
    temp_r1                      = *(s8 *) ((u8 *) &data_02121950 + temp_r0);
    M2C_FIELD(arg0, s32 *, 0x34) = M2C_FIELD(arg0, s32 *, 0x34) + temp_r1;
}
