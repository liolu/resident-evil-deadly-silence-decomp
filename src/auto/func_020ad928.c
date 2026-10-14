/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02147cc0;

void func_020ad928(s32 arg0) {
    if ((M2C_FIELD(&data_02143cc0, u8 *, 0xFD5) == 4) && (arg0 == 0)) {
        return;
    }
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4E) = (u8) *M2C_FIELD(&data_02147cc0, u8 **, 0x53C);
}
