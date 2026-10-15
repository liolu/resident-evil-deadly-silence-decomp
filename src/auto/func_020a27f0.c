/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020b818c(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;
extern M2C_UNK data_02144cc0;
extern M2C_UNK data_02147cc0;

s32 func_020a27f0(s32 arg0) {
    if ((M2C_FIELD(&data_02143cc0, u8 *, 0xFDA) == 0) && !(M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x7F00) &&
        (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & 0x40)) {
        M2C_FIELD(&data_02147cc0, s8 *, 0x543) = 1;
        M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & ~0x45);
        func_020b818c(0x2A, &data_02144c34, 0);
        M2C_FIELD(&data_02144cc0, s32 *, 0xDC) = arg0;
    }
    return 0;
}
