/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern void *data_0213daa8;
extern M2C_UNK data_02144bc0;

s32 func_020b3e8c(void) {
    u16 temp_r3;
    void *temp_ip;

    temp_ip       = data_0213daa8;
    data_0213daa8 = temp_ip + 6;
    temp_r3       = M2C_FIELD(temp_ip, u16 *, 2);
    if ((s32) (u16) (M2C_FIELD(&data_02144bc0, s16 *, 0x88) - temp_r3) <= (s32) (M2C_FIELD(temp_ip, u16 *, 4) - temp_r3)) {
        return 1;
    }
    return 0;
}
