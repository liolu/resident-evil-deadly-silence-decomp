/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0215301c;

void func_020e5f14(void) {
    if (M2C_FIELD(&data_0215301c, M2C_UNK (**)(s32), 0) == NULL) {
        return;
    }
    M2C_FIELD(&data_0215301c, M2C_UNK (**)(s32), 0)(M2C_FIELD(&data_0215301c, s32 *, 4));
}
