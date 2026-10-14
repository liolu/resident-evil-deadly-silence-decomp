/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020da7a0(M2C_UNK, u16 *, M2C_UNK);         /* extern */
s32 func_020da998(u16 *);                           /* extern */
s32 func_020db174(M2C_UNK, u16 *, M2C_UNK);         /* extern */
s32 func_020db374(u16 *);                           /* extern */
s32 func_020dc210(M2C_UNK, u16 *, M2C_UNK);         /* extern */
M2C_UNK func_020dc658();                            /* extern */
s32 func_020dc8d4(u16 *);                           /* extern */
s32 func_020dca38(M2C_UNK, u16 *, M2C_UNK);         /* extern */
s32 func_020dccc0(u16 *);                           /* extern */
s32 func_020dd0e0(M2C_UNK, u16 *, M2C_UNK);         /* extern */

s32 func_020dc068(M2C_UNK arg0, u16 *arg1, M2C_UNK arg2) {
    u16 temp_r0;

    func_020dc658();
    temp_r0 = *arg1;
    if ((u16) (s16) ((u8) ((s32) temp_r0 >> 8) | ((temp_r0 << 8) & 0xFF00)) == 0x8000) {
        return func_020dc210(arg0, arg1, arg2);
    }
    if (func_020dc8d4(arg1) != 0) {
        return func_020dca38(arg0, arg1, arg2);
    }
    if (func_020dccc0(arg1) != 0) {
        return func_020dd0e0(arg0, arg1, arg2);
    }
    if (func_020da998(arg1) != 0) {
        return func_020da7a0(arg0, arg1, arg2);
    }
    if (func_020db374(arg1) == 0) {
        return -1;
    }
    return func_020db174(arg0, arg1, arg2);
}
