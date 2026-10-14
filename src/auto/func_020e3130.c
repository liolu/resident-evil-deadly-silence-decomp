#include "m2c.h"

void func_020e3130(void *arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    *arg1 = M2C_FIELD(arg0, s16 *, 0x34);
    *arg2 = M2C_FIELD(arg0, s16 *, 0x36);
    *arg3 = M2C_FIELD(arg0, s16 *, 0x38);
}
