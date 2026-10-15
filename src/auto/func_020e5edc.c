/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0215301c;

void func_020e5edc(void) {
    if (M2C_FIELD(&data_0215301c, M2C_UNK(**)(s32), 8) == NULL) {
        return;
    }
    M2C_FIELD(&data_0215301c, M2C_UNK(**)(s32), 8)(M2C_FIELD(&data_0215301c, s32 *, 0xC));
}
