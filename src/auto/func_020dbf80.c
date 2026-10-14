#include "m2c.h"

s32 func_020dbf80(void *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return M2C_FIELD(arg0, s32 *, 0x2C);
}
