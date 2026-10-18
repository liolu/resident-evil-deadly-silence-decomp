/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020b6b5c();                                /* extern */
M2C_UNK func_020b81e4(u16, void *, M2C_UNK);        /* extern */
extern M2C_UNK data_02121cac;

void func_020abd10(void *arg0) {
    func_020b81e4(((s16 *) &data_02121cac)[(func_020b6b5c() + (M2C_FIELD(arg0, u8 *, 9) * 2))], arg0 + 0x30, 0);
}
