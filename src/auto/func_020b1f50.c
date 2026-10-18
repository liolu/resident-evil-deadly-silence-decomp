/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02053e90(u8);                              /* extern */
extern M2C_UNK data_02122550;

u8 func_020b1f50(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 4) = func_02053e90(M2C_FIELD(arg0, u8 *, 2));
    return ((s8 *) &data_02122550)[M2C_FIELD(arg0, u8 *, 3)];
}
