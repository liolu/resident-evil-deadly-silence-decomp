#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02144bc0;
extern s32 data_027e0018;

s32 func_0204dc40(void) {
    if ((s32) data_027e0018 >= 0x7D0) {
        return 0;
    }
    if ((s32) M2C_FIELD(&data_02144bc0, s16 *, 0xD8) >= 0xA) {
        return 1;
    }
    return 0;
}
