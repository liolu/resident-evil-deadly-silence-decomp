/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e53c4(s32);                         /* extern */
M2C_UNK func_020e5540(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_020e5d64(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern s32 data_02127960;
extern M2C_UNK data_02130d40;
extern M2C_UNK data_02130d44;
extern M2C_UNK func_020e5430;
extern M2C_UNK func_020e5ecc;
extern M2C_UNK func_020e8764;

void func_020e5e68(void) {
    func_020e53c4(data_02127960);
    func_020e5540(&func_020e5ecc, 0);
    func_020e5d64(&data_02130d40, &func_020e8764, 0);
    func_020e5d64(&data_02130d44, &func_020e5430, 0);
}
