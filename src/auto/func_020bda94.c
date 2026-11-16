/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0213b890;

s32 func_020bda94(s32 arg0) {
    s32 var_lr;
    u16 temp_r3;
    u16 temp_r2;
    void *temp_r1;

    var_lr  = 1;
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0xC);
    temp_r3 = M2C_FIELD(temp_r1, u16 *, 0);
    temp_r2 = M2C_FIELD(temp_r1, u16 *, 2);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0xC) = (void *) ((u8 *) temp_r1 + 4);
    if (temp_r3 != 0) {
        s32 t = (u16) (temp_r3 + (arg0 - temp_r2));
        if (t > (s32) (temp_r3 * 2)) {
            var_lr = 0;
        }
    }
    return var_lr;
}
