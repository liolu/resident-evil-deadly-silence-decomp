/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_02060540();                            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_02121340;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213be00;
extern M2C_UNK data_021483e0;

s32 func_020609d8(void) {
    s32 temp_r1;
    s32 var_r4;

    var_r4 = 1;
    func_02056fb0(0x11);
    func_02056fb0(0x14);
    func_02056fb0(0x15);
    func_02056fb0(0x16);
    if (func_020b39e4(&data_0213be00, 0x7F) == 0) {
        M2C_FIELD(&data_02121340, M2C_UNK(**)(M2C_UNK *), 0x10)(&data_021483e0);
        var_r4                                 = 0;
        temp_r1                                = M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x400;
        M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = temp_r1;
        M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (temp_r1 & ~0x800);
    }
    func_02060540();
    return var_r4;
}
