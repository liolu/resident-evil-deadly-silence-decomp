/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_02003a0c(M2C_UNK);                     /* extern */
M2C_UNK func_02003ad8(M2C_UNK);                     /* extern */
M2C_UNK func_0200f6e0(M2C_UNK);                     /* extern */
M2C_UNK func_02013638(M2C_UNK, M2C_UNK, s32);       /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020c4778(M2C_UNK);                     /* extern */
M2C_UNK func_020d5e88(M2C_UNK);                     /* extern */
extern M2C_UNK data_02126880;
extern M2C_UNK data_02126954;
extern M2C_UNK data_0213ad48;
extern u8 data_0213ae0c;
extern M2C_UNK data_0213b890;

void func_020d657c(void) {
    u8 var_r3;

    func_02003a0c(7);
    func_0200f6e0(7);
    func_020038b8(&data_02126880);
    func_020d5e88(1);
    M2C_FIELD(&data_0213b890, s8 *, 0x53) = 0;
    func_02003ad8(8);
    if (data_0213ae0c != 0) {
        var_r3 = 1;
    } else {
        var_r3 = 0;
    }
    func_02013638(0, 0, ((s32 *) &data_02126954)[((M2C_FIELD(&data_0213ad48, u8 *, 3) * 3) + var_r3)]);
    func_02013638(1, 0, ((s32 *) &data_02126954)[((M2C_FIELD(&data_0213ad48, u8 *, 3) * 3) + 2)]);
    func_020c4778(1);
    func_0206fcf8(3, 2, 0, 0x40);
}
