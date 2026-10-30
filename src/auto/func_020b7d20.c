/* compiler: 1.2/sp2p3 -O2 */
#include "m2c.h"

M2C_UNK func_0200d65c();                            /* extern */
extern M2C_UNK data_0213ac6c;

void func_020b7d20(void) {
    s32 temp_ip;
    s32 var_lr;
    u8 temp_r2;

    func_0200d65c();
    var_lr = 0;
    do {
        temp_ip = (var_lr * 0xC) + (s32) &data_0213ac6c;
        temp_r2 = M2C_FIELD(temp_ip, u8 *, 1);
        var_lr += 1;
        if (temp_r2 != 0) {
            M2C_FIELD(temp_ip, s8 *, 1) = 4;
            M2C_FIELD(temp_ip, s8 *, 0) = 4;
        }
    } while (var_lr < 5);
}
