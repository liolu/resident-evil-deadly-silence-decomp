/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020ad928(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02147cc0;

s32 func_020a5760(void *arg0) {
    u8 temp_r1;

    if (!(M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 0x40)) {
        return 0;
    }
    temp_r1 = M2C_FIELD(arg0, u8 *, 0xA);
    if ((u32) (temp_r1 - 1) > 9U) {
        return 0;
    }
    if (temp_r1 == *M2C_FIELD(&data_02147cc0, u8 **, 0x53C)) {
        return 1;
    }
    func_020ad928(0);
    return 0;
}
