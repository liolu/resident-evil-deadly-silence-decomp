/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_02092bac();                            /* extern */
M2C_UNK func_020b67e8();                            /* extern */
M2C_UNK func_020b80e4();                            /* extern */
extern M2C_UNK data_02121340;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_021483bc;

s32 func_0206f548(void) {
    s32 temp_ip;
    s32 temp_lr;

    func_02056fb0(4);
    M2C_FIELD(&data_02121340, M2C_UNK(**)(M2C_UNK *), 4)(&data_021483bc);
    func_020b67e8();
    func_020b80e4();
    temp_lr                                = M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & ~0x20000;
    temp_ip                                = temp_lr & ~0x10000;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = temp_lr;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = temp_ip;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (temp_ip & ~0x100000);
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) | 0x14F);
    func_02092bac();
    return 0;
}
