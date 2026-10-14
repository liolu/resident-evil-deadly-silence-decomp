#include "m2c.h"
#include "engine.h"

extern void **data_027e000c;

void func_0209fba4(s32 arg0) {
    void *temp_r2;

    temp_r2 = *data_027e000c;
    M2C_FIELD(temp_r2, s32 *, 0x74) = (s32) (M2C_FIELD(temp_r2, s32 *, 0x74) & ~(1 << arg0));
}
