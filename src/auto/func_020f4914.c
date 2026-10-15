/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020fe144(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_020fe364(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_020fe6f8(M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
extern M2C_UNK data_021543a4;
extern M2C_UNK data_021543f0;
extern M2C_UNK data_02154460;
extern M2C_UNK data_021544d4;
extern M2C_UNK data_02154504;

void func_020f4914(void) {
    func_020fe144(&data_02154460, &data_021543f0, &data_021544d4);
    func_020fe6f8(&data_021544d4, &data_021544d4, M2C_FIELD(&data_021543a4, s32 *, 0xEC),
                  M2C_FIELD(&data_021543a4, s32 *, 0xF0), M2C_FIELD(&data_021543a4, s32 *, 0xF4));
    func_020fe364(&data_021544d4, &data_02154504);
}
