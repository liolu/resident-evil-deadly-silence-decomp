#include "m2c.h"
#include "engine.h"

void func_0208ad28(s32 arg0) {
    if (M2C_FIELD(arg0, volatile u8 *, 0) == 0) {
        return;
    }
    M2C_FIELD(arg0, volatile u8 *, 1) = (u8) (M2C_FIELD(arg0, volatile u8 *, 1) - 1);
    if (M2C_FIELD(arg0, volatile u8 *, 1) == 0) {
        M2C_FIELD(arg0, volatile u8 *, 0) = 0U;
    }
}
