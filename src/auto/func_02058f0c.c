/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020b5080(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c04;

s32 func_02058f0c(void *arg0) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 4);
    if (&data_02144c04 == temp_r2) {
        M2C_FIELD(&data_02143cc0, s8 *, 0xFDA) = 0;
        func_020b5080(1, 0, 0, 0);
    } else {
        M2C_FIELD(temp_r2, s8 *, 0x90) = 1;
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x91) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x92) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x93) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x96) = 0;
    }
    return 1;
}
