/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020751c4();                            /* extern */
M2C_UNK func_020ad928(M2C_UNK);                     /* extern */
M2C_UNK func_020b6e58();                            /* extern */
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213bf2c;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02147cc0;

void func_0207511c(s8 arg0) {
    M2C_FIELD(&data_0213bdcc, s8 *, 1) = arg0;
    if (arg0 == 0) {
        M2C_FIELD(&data_02147cc0, M2C_UNK **, 0x53C) = &data_0213bf2c;
    } else {
        M2C_FIELD(&data_02147cc0, M2C_UNK **, 0x53C) = (M2C_UNK *) (M2C_FIELD(&data_02147cc0, s32 *, 0x538) + ((arg0 - 1) * 2));
    }
    func_020751c4();
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4E) != 1) {
        func_020ad928(0);
    }
    func_020b6e58();
}
