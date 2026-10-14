#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144cc0;

s32 func_020add50(void) {
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4E) == 1) {
        return M2C_FIELD(&data_02144cc0, s32 *, 0xD0);
    }
    return M2C_FIELD(&data_02144cc0, s32 *, 0xCC);
}
