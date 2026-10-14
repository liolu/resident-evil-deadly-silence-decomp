#include "m2c.h"

u32 func_020e8874(void *arg0) {
    if (arg0 == NULL) {
        return 0U;
    }
    return (u32) M2C_FIELD(arg0, u32 *, 0x1C) >> 1;
}
