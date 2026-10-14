#include "m2c.h"
#include "engine.h"

extern void *data_027e000c;

void func_0204ec28(void) {
    M2C_FIELD(data_027e000c, s16 *, 0x17E) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x17E) + 0x200);
    if ((s32) M2C_FIELD(data_027e000c, s16 *, 0x17E) < 0x1600) {
        return;
    }
    M2C_FIELD(data_027e000c, s16 *, 0x17E) = 0x1600;
    M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
}
