/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207544c(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_0213ad48;

void func_0201893c(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if ((M2C_FIELD(arg0, u8 *, 0x90) == 1) &&
        (((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && (M2C_FIELD(arg0, u8 *, 0x169) & 1)) ||
         (M2C_FIELD(arg0, u8 *, 0x16B) == 2))) {
        func_0207544c(arg1, arg2);
        return;
    }
    func_02075738(arg1, arg2);
}
