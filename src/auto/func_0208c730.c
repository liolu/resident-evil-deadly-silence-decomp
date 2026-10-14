#include "m2c.h"
#include "engine.h"

void func_0208c730(s32 arg0) {
    if ((s32) M2C_FIELD(arg0, s16 *, 2) < 0x10) {
        M2C_FIELD(arg0, s16 *, 2) = 0x10;
    }
    if ((s32) M2C_FIELD(arg0, s16 *, 2) > 0xB0) {
        M2C_FIELD(arg0, s16 *, 2) = 0xB0;
    }
    if ((s32) M2C_FIELD(arg0, s16 *, 0) < 0x10) {
        M2C_FIELD(arg0, s16 *, 0) = 0x10;
    }
    if ((s32) M2C_FIELD(arg0, s16 *, 0) > 0xF0) {
        M2C_FIELD(arg0, s16 *, 0) = 0xF0;
    }
}
