#include "m2c.h"
#include "engine.h"

extern void **data_027e000c;

void func_0209fbcc(s32 arg0) {
    void *temp_r3;

    temp_r3 = *data_027e000c;
    M2C_FIELD(temp_r3, s32 *, 0x74) = (s32) (M2C_FIELD(temp_r3, s32 *, 0x74) | (1 << arg0));
}
