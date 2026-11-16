#include "m2c.h"

extern M2C_UNK data_02144da8;
extern u8 data_02147cc0[];
extern u8 data_0214813d[];
extern u8 data_0214813e[];

s32 func_02053cc8(u8 *arg0) {
    u8 idx;

    if (arg0 == NULL) {
        return 0;
    }
    if (data_02147cc0[0x47C] == 0) {
        return 0;
    }
    idx = data_0214813e[(s32) ((s8) arg0[6]) * 4];
    return ((s32) &data_02144da8) + data_0214813d[idx * 4] * 0x19C;
}
