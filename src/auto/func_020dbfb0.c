#include "m2c.h"

s32 func_020dbfb0(void *arg0) {
    s16 t;
    s16 u;

    t = M2C_FIELD(arg0, s16 *, 0x98);
    if (t == 0) {
        return 0x10;
    }
    if (t == 2) {
        u = M2C_FIELD(arg0, s16 *, 0x9C);
        if (u == 2) {
            return 4;
        }
        if (u == 1) {
            return 8;
        }
        return 0x10;
    }
    if (t == 1) {
        if (M2C_FIELD(arg0, s16 *, 0x9C) == 2) {
            return 4;
        }
        return 0x10;
    }
    return 0x10;
}
