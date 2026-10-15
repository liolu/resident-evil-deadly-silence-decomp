/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213ad48;

void func_0201840c(void *arg0) {
    u8 temp_r1;
    u8 temp_r2;

    if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
        M2C_FIELD(arg0, s8 *, 0x198) = 4;
        temp_r2                      = M2C_FIELD(arg0, u8 *, 0x169);
        if (!(temp_r2 & 1) && !(temp_r2 & 2) && !(temp_r2 & 4)) {
            return;
        }
        M2C_FIELD(arg0, s8 *, 0x198) = 7;
        return;
    }
    temp_r1 = M2C_FIELD(arg0, u8 *, 9);
    switch ((s32) temp_r1) {                        /* irregular */
        case 1:
            M2C_FIELD(arg0, s8 *, 0x198) = 6;
            break;
        case 22:
            M2C_FIELD(arg0, s8 *, 0x198) = 7;
            break;
        case 17:
        case 0:
            M2C_FIELD(arg0, s8 *, 0x198) = 5;
            break;
    }
    if ((M2C_FIELD(arg0, u8 *, 0xA) & 0xF) == 0xE) {
        M2C_FIELD(arg0, s8 *, 0x198) = 7;
    }
}
