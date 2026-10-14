#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144cc0;

s32 func_02072d94(void) {
    if (M2C_FIELD(&data_02144cc0, u8 *, 0xAC) != 0) {
        return 0;
    }
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xF43) == 0) {
        return 1;
    }
    return 0;
}
