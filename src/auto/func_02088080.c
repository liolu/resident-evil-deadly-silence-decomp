/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021375ac;
extern M2C_UNK data_02143cc0;

void func_02088080(void) {
    if (M2C_FIELD(&data_021375ac, u8 *, 0x29) != 0xF) {
        return;
    }
    if (M2C_FIELD(&data_021375ac, u8 *, 0x2A) != 0x18) {
        return;
    }
    if (M2C_FIELD(&data_021375ac, u8 *, 0x2B) == 6) {
        M2C_FIELD(&data_02143cc0, s8 *, 0x150) = 0;
    }
}
