/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 func_0200ea0c(void *, s32, u8);                  /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0214bcc0;

void func_02049d68(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 9) == 0x12) {
        M2C_FIELD(arg0, u8 *, 0xB) =
            func_0200ea0c(arg0 + 0x30, M2C_FIELD(&data_0214bcc0, s32 *, 0x7B0), M2C_FIELD(arg0, u8 *, 0xB));
        return;
    }
    if (M2C_FIELD(&data_0213ad98, u8 *, 2) == 5) {
        M2C_FIELD(arg0, u8 *, 0xB) = 0U;
        return;
    }
    M2C_FIELD(arg0, u8 *, 0xB) =
        func_0200ea0c(arg0 + 0x30, M2C_FIELD(&data_0214bcc0, s32 *, 0x7B0), M2C_FIELD(arg0, u8 *, 0xB));
}
