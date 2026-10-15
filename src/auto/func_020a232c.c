/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02074ef0(M2C_UNK);                         /* extern */
M2C_UNK func_02092dd4(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02144cc0;
extern M2C_UNK data_0214bcc0;

s32 func_020a232c(void *arg0) {
    s32 temp_r0;

    if (!(M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x7F00) && (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & 0x40)) {
        temp_r0 = func_02074ef0(0x2F);
        if (temp_r0 >= 0) {
            M2C_FIELD(&data_02144cc0, void **, 0xDC) = arg0;
            M2C_FIELD(arg0, s16 *, 2)                = (s16) temp_r0;
            M2C_FIELD(&data_0213daa8, u16 *, 0x74)   = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & ~0x45);
            M2C_FIELD(&data_0214bcc0, s8 *, 0x7A8)   = 1;
        } else {
            func_02092dd4(0xDE, 0xFF);
        }
    }
    return 0;
}
