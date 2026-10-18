/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0211dcfc;

void func_020b9e50(void *arg0, void *arg1) {
    u16 temp_r2;
    u8 temp_ip;

    temp_ip = *((u8 *) ((s8 *) &data_0211dcfc + (M2C_FIELD(arg1, u8 *, 0) * 4)));
    temp_r2 = M2C_FIELD(arg0, u8 *, 1) + M2C_FIELD(arg1, u8 *, 1);
    if ((s32) temp_r2 > (s32) temp_ip) {
        M2C_FIELD(arg1, u8 *, 1) = temp_ip;
        M2C_FIELD(arg0, u8 *, 1) = (u8) (temp_r2 - temp_ip);
        return;
    }
    M2C_FIELD(arg1, u8 *, 1) = (u8) temp_r2;
    M2C_FIELD(arg0, s8 *, 0) = 0;
}
