/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02092dd4(M2C_UNK, M2C_UNK);            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213be00;
extern M2C_UNK data_02147cc0;

void func_020a1f18(void) {
    if (func_020b39e4(&data_0213be00, 0x7C) != 0) {
        M2C_FIELD(&data_0213ad98, s8 *, 6) = 0xD;
    } else {
        M2C_FIELD(&data_0213ad98, s8 *, 6) = 0x3D;
    }
    func_02092dd4(0xD9, 0xFF);
    M2C_FIELD(&data_02147cc0, s8 *, 0x542) = 3;
}
