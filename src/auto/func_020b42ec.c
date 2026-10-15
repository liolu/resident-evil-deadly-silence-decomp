/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern void *data_0213daa8;
extern M2C_UNK data_0214bcc0;

s32 func_020b42ec(void) {
    s32 temp_r2;
    u8 temp_lr;
    void *temp_r1;

    temp_r1       = data_0213daa8;
    data_0213daa8 = temp_r1 + 0xC;
    temp_lr       = M2C_FIELD(temp_r1, u8 *, 3);
    temp_r2 =
        (M2C_FIELD(temp_r1, u8 *, 2) * 0xC) +
        M2C_FIELD((M2C_FIELD(M2C_FIELD(&data_0214bcc0, void **, 0x7AC), s32 *, 0x4C) + (M2C_FIELD(temp_r1, u8 *, 1) * 4)),
                  s32 *, 4);
    if (temp_lr != 0) {
        M2C_FIELD(temp_r2, u16 *, 0xA) = (u16) (M2C_FIELD(temp_r2, u16 *, 0xA) & 0xF0FF);
        M2C_FIELD(temp_r2, u16 *, 0xA) = (u16) (M2C_FIELD(temp_r2, u16 *, 0xA) | ((temp_lr << 8) & 0xF00));
    }
    M2C_FIELD(temp_r2, u16 *, 4) = (u16) M2C_FIELD(temp_r1, u16 *, 4);
    M2C_FIELD(temp_r2, u16 *, 6) = (u16) M2C_FIELD(temp_r1, u16 *, 6);
    M2C_FIELD(temp_r2, u16 *, 0) = (u16) M2C_FIELD(temp_r1, u16 *, 8);
    M2C_FIELD(temp_r2, u16 *, 2) = (u16) M2C_FIELD(temp_r1, u16 *, 0xA);
    return 1;
}
