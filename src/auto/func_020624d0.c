/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_0206225c();                            /* extern */
M2C_UNK func_02092bac();                            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020b67e8();                            /* extern */
extern M2C_UNK data_02121340;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213be88;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_021483ec;

s32 func_020624d0(void) {
    s32 temp_ip;
    s32 temp_lr;
    s32 temp_r1;
    s32 var_r4;

    var_r4 = 1;
    func_02056fb0(1);
    func_020b67e8();
    temp_lr = M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & ~0x20000;
    temp_ip = temp_lr & ~0x10000;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = temp_lr;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = temp_ip;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (temp_ip & ~0x100000);
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) | 0x14F);
    func_02092bac();
    if (func_020b39e4(&data_0213be88, 0xE) != 0) {
        M2C_FIELD(&data_02121340, M2C_UNK (**)(M2C_UNK *), 0x10)(&data_021483ec);
        var_r4 = 0;
        temp_r1 = M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x400;
        M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = temp_r1;
        M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (temp_r1 & ~0x800);
    }
    func_0206225c();
    return var_r4;
}
