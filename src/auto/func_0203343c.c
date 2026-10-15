/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02143cc0;

void func_0203343c(void) {
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xFD4) != 6) {
        return;
    }
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xFD5) != 8) {
        return;
    }
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xFD6) != 1) {
        return;
    }
    if ((s32) M2C_FIELD(&data_02143cc0, s32 *, 0xF78) < -0x1F4) {
        M2C_FIELD(&data_02143cc0, u8 *, 0xFD6) = 0U;
        M2C_FIELD(&data_02143cc0, s8 *, 0xFD7) = 0xC;
        return;
    }
    M2C_FIELD(&data_02143cc0, s32 *, 0xF78) = 0;
    M2C_FIELD(&data_02143cc0, u8 *, 0xFD6)  = 0U;
    M2C_FIELD(&data_02143cc0, s8 *, 0xFD7)  = 9;
}
