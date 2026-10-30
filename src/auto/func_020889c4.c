/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02014908();                            /* extern */
M2C_UNK func_02083964(s32);                         /* extern */
M2C_UNK func_020882e4();                            /* extern */
M2C_UNK func_02088a20();                            /* extern */
M2C_UNK func_0208d61c(s32);                         /* extern */
M2C_UNK func_020b72d0();                            /* extern */
extern M2C_UNK data_021375ac;

void func_020889c4(void) {
    if (M2C_FIELD(&data_021375ac, s32 *, 0x64) != 0) {
        func_020882e4();
        func_02014908();
        func_0208d61c(M2C_FIELD(&data_021375ac, s32 *, 0x64));
        func_02083964(M2C_FIELD(&data_021375ac, s32 *, 0x64) + 0x4C8);
        func_020b72d0();
        func_02088a20();
    }
}
