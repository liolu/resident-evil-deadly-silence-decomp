/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02059bcc(M2C_UNK *, u8);                   /* extern */
M2C_UNK func_020b5080(M2C_UNK, u8, M2C_UNK, u8);    /* extern */
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c04;

s32 func_020b4424(void) {
    u8 temp_r3;
    u8 temp_r4;
    u8 temp_r5;

    temp_r5                               = M2C_FIELD(M2C_FIELD(&data_0213daa8, void **, 0), u8 *, 2);
    temp_r4                               = M2C_FIELD(M2C_FIELD(&data_0213daa8, void **, 0), u8 *, 3);
    temp_r3                               = M2C_FIELD(M2C_FIELD(&data_0213daa8, void **, 0), u8 *, 1) + 2;
    M2C_FIELD(&data_0213daa8, void **, 0) = (void *) (M2C_FIELD(&data_0213daa8, void **, 0) + 4);
    func_020b5080(8, M2C_FIELD(&data_02143cc0, u8 *, 0xFD5), 0, temp_r3);
    M2C_FIELD(&data_0213daa8, s32 *, 0x240) = func_02059bcc(&data_02144c04, temp_r5);
    M2C_FIELD(&data_02143cc0, u8 *, 0xFE6)  = temp_r4;
    M2C_FIELD(&data_02143cc0, s8 *, 0xFDC)  = 0;
    M2C_FIELD(&data_02143cc0, s8 *, 0xFE7)  = 0;
    return 1;
}
