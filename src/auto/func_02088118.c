/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;
extern M2C_UNK data_02143cc0;

void func_02088118(void) {
    if (M2C_FIELD(&data_021375ac, u8 *, 0x29) != 0xF) {
        return;
    }
    if (M2C_FIELD(&data_021375ac, u8 *, 0x2A) != 0x12) {
        return;
    }
    M2C_FIELD(&data_02143cc0, s8 *, 0x188) = 0;
    M2C_FIELD(&data_02143cc0, s8 *, 0x1C0) = 1;
    M2C_FIELD(&data_021375ac, s8 *, 0x12)  = 1;
}
