/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_02121e70;
extern M2C_UNK data_02121e71;

s32 func_02058d90(void *arg0) {
    u8 temp_ip;
    u8 temp_r3;
    void *temp_ip_2;
    void *temp_r2;
    void *temp_r2_2;

    temp_ip                                            = M2C_FIELD(M2C_FIELD(arg0, void **, 8), u8 *, 1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), u8 *, 0xA2) = temp_ip;
    *M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0), s32 **, 0x10) = temp_ip << 0xC;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0xA3)                           = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x98)                           = 7;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0xA6)                          = 0;
    temp_r2                                                                      = M2C_FIELD(arg0, void **, 4);
    if (M2C_FIELD(temp_r2, u16 *, 0xEC) & 0x20) {
        M2C_FIELD(temp_r2, s8 *, 0x98) = 0;
    }
    temp_ip_2 = M2C_FIELD(arg0, void **, 4);
    if ((u32) M2C_FIELD(temp_ip_2, u8 *, 9) < 0x20U) {
        temp_r3 = M2C_FIELD(temp_ip_2, u8 *, 0xA1);
        if ((u32) temp_r3 > 0xFU) {
            M2C_FIELD(temp_ip_2, s8 *, 0x93) = 3;
        } else {
            M2C_FIELD(temp_ip_2, s8 *, 0x93) = (s8) (*((u8 *) ((s8 *) &data_02121e70 + (temp_r3 * 2))) + 1);
            temp_r2_2                        = M2C_FIELD(arg0, void **, 4);
            M2C_FIELD(temp_r2_2, u8 *, 0xA1) =
                (u8) * ((u8 *) ((s8 *) &data_02121e71 + (M2C_FIELD(temp_r2_2, u8 *, 0xA1) * 2)));
        }
    } else {
        M2C_FIELD(temp_ip_2, s8 *, 0x93) = 1;
    }
    return 2;
}
