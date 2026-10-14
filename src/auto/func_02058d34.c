/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02058d34(void *arg0) {
    u8 temp_ip;
    void *temp_r1;

    temp_ip = M2C_FIELD(M2C_FIELD(arg0, void **, 8), u8 *, 1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), u8 *, 0xA2) = temp_ip;
    *M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0), s32 **, 0x10) = temp_ip << 0xC;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0xA3) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x98) = 7;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0xA6) = 0;
    temp_r1 = M2C_FIELD(arg0, void **, 4);
    if (M2C_FIELD(temp_r1, u16 *, 0xEC) & 0x20) {
        M2C_FIELD(temp_r1, s8 *, 0x98) = 0;
    }
    return 2;
}
