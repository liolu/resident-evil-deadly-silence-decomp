/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

s32 func_0208b3c4(s32 arg0) {
    u8 temp_r1;
    u8 temp_r2;

    temp_r2 = M2C_FIELD(arg0, u8 *, 0x90);
    if (temp_r2 == 4) {
        return 4;
    }
    temp_r1 = M2C_FIELD(arg0, u8 *, 0x17A);
    if (temp_r1 == 1) {
        return 2;
    }
    if (temp_r1 == 2) {
        return 3;
    }
    if ((temp_r2 == 1) && (M2C_FIELD(arg0, u8 *, 0x91) == 0) && (M2C_FIELD(arg0, u8 *, 0x92) == 0) && (M2C_FIELD(arg0, u8 *, 0x93) != 0)) {
        return 1;
    }
    return 0;
}
