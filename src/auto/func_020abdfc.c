/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020b6b5c();                                /* extern */
M2C_UNK func_020b81e4(u16, void *, M2C_UNK);        /* extern */
extern M2C_UNK data_02121d78;
extern M2C_UNK data_02121dc0;
extern M2C_UNK data_02144c04;

void func_020abdfc(s32 arg0, void *arg1) {
    u8 *var_r1;
    u8 var_r0;

    if (func_020b6b5c() != 0) {
        var_r1 = (u8 *) &data_02121dc0;
    } else {
        var_r1 = (u8 *) &data_02121d78;
    }
    if (arg1 != &data_02144c04) {
        var_r0 = M2C_FIELD(arg1, u8 *, 9) - 0x20;
    } else {
        var_r0 = M2C_FIELD(arg1, u8 *, 9);
    }
    func_020b81e4(*(u16 *) (var_r1 + ((arg0 + (var_r0 * 4)) * 2)), arg1 + 0x30, 0);
}
