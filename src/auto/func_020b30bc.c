/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern void *data_0213daa8;
extern M2C_UNK data_02147cc0;
extern M2C_UNK data_0214838c;

s32 func_020b30bc(void) {
    u32 temp_ip;
    void *temp_lr;

    temp_lr = data_0213daa8;
    data_0213daa8 = temp_lr + 0x12;
    temp_ip = (M2C_FIELD(temp_lr, u8 *, 1) * 0xC) + (s32) &data_0214838c;
    if (temp_ip > (u32) M2C_FIELD(&data_02147cc0, u32 *, 0x84C)) {
        M2C_FIELD(&data_02147cc0, u32 *, 0x84C) = temp_ip;
    }
    M2C_FIELD(temp_ip, u8 *, 0) = (u8) M2C_FIELD(temp_lr, u8 *, 0xA);
    M2C_FIELD(temp_ip, u8 *, 1) = (u8) M2C_FIELD(temp_lr, u8 *, 0xB);
    M2C_FIELD(temp_ip, u16 *, 2) = (u16) M2C_FIELD(temp_lr, u16 *, 0xC);
    M2C_FIELD(temp_ip, u16 *, 4) = (u16) M2C_FIELD(temp_lr, u16 *, 0xE);
    M2C_FIELD(temp_ip, u16 *, 6) = (u16) M2C_FIELD(temp_lr, u16 *, 0x10);
    M2C_FIELD(temp_ip, void **, 8) = (void *) (temp_lr + 2);
    return 1;
}
