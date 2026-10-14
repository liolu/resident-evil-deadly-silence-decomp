#include "m2c.h"
#include "engine.h"

extern void *data_02137264;

void func_02005c14(s32 arg0, s32 arg1) {
    if (data_02137264 != NULL) {
        M2C_FIELD(data_02137264, s16 *, 4) = (s16) arg0;
        M2C_FIELD(data_02137264, s16 *, 6) = (s16) arg1;
    }
}
