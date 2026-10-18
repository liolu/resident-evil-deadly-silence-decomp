/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0212e36c;

void func_0208358c(void *arg0, u32 arg1) {
    s32 temp_ip;

    temp_ip = arg1 & 0x80;
    if ((temp_ip == 0) && (arg1 >= 0x11U)) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x91) = (s8) arg1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x92) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x93) = 0;
    if (temp_ip == 0) {
        M2C_FIELD(arg0, u8 *, 5) = (u8) ((u8 *) &data_0212e36c)[arg1];
    } else {
        M2C_FIELD(arg0, u8 *, 5) = 0U;
    }
    M2C_FIELD(arg0, u8 *, 0xD) = (u8) (M2C_FIELD(arg0, u8 *, 0xD) & ~0x20);
    M2C_FIELD(arg0, u8 *, 0xD) = (u8) (M2C_FIELD(arg0, u8 *, 0xD) & ~0x40);
}
