#include "engine.h"
#include "m2c.h"

extern void *data_027e000c;

void func_02051218(void) {
    M2C_FIELD(data_027e000c, s32 *, 0x184) =
        (s32) (M2C_FIELD(data_027e000c, s32 *, 0x184) + M2C_FIELD(data_027e000c, s32 *, 0x17C));
    M2C_FIELD(data_027e000c, s32 *, 0x188) =
        (s32) (M2C_FIELD(data_027e000c, s32 *, 0x188) + M2C_FIELD(data_027e000c, s32 *, 0x180));
    M2C_FIELD(data_027e000c, s32 *, 0x30) = (s32) ((s32) M2C_FIELD(data_027e000c, s32 *, 0x184) >> 0x10);
    M2C_FIELD(data_027e000c, s32 *, 0x38) = (s32) ((s32) M2C_FIELD(data_027e000c, s32 *, 0x188) >> 0x10);
}
