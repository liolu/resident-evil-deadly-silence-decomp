/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020d73ec(u16);                             /* extern */
M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
extern M2C_UNK data_02126d70;
extern M2C_UNK (*data_0213ad20)(M2C_UNK *, u16, u16);
extern M2C_UNK data_02141cc0;

void func_020d7318(void *arg0) {
    s32 temp_r0;
    u16 temp_ip;
    u16 temp_r3;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020d87f0();
        func_020d880c(9);
        return;
    }
    if (data_0213ad20 != NULL) {
        data_0213ad20(&data_02126d70, M2C_FIELD(arg0, u16 *, 8), M2C_FIELD(arg0, u16 *, 0xA));
    }
    temp_r3 = M2C_FIELD(arg0, u16 *, 0xA);
    temp_ip = M2C_FIELD(arg0, u16 *, 8);
    if ((u32) M2C_FIELD(&data_02141cc0, u16 *, 0x5E) > (u32) temp_r3) {
        M2C_FIELD(&data_02141cc0, u16 *, 0x5E) = temp_r3;
        M2C_FIELD(&data_02141cc0, u16 *, 0x60) = (u16) (1 << (temp_ip - 1));
    } else if (M2C_FIELD(&data_02141cc0, u16 *, 0x5E) == temp_r3) {
        M2C_FIELD(&data_02141cc0, u16 *, 0x60) = (u16) (M2C_FIELD(&data_02141cc0, u16 *, 0x60) | (1 << (temp_ip - 1)));
    }
    temp_r0 = func_020d73ec((u16) (temp_ip + 1));
    if (temp_r0 == 0x18) {
        func_020d880c(7);
        return;
    }
    if (temp_r0 != 2) {
        func_020d880c(9);
    }
}
