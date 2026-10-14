/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02070110(M2C_UNK *, M2C_UNK *);        /* extern */
s32 func_02104778(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_02109860(M2C_UNK);                     /* extern */
s32 func_0210989c(s32, s32);                        /* extern */
extern M2C_UNK data_0211d88c;
extern M2C_UNK data_0213ade4;

void func_02070460(void) {
    s32 temp_r0;

    func_02109860(3);
    temp_r0 = func_0210989c(0, 0);
    func_0210989c(func_02104778(0, temp_r0, 4), temp_r0);
    func_02070110(&data_0213ade4, &data_0211d88c);
}
