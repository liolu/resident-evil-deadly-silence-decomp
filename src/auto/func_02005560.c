#include "engine.h"
#include "m2c.h"

extern void *data_02137264;

s32 func_02005560(void) {
    if (data_02137264 != NULL) {
        return M2C_FIELD(data_02137264, s32 *, 8);
    }
    return 0;
}
