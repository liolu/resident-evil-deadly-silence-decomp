#include "m2c.h"

extern s16 data_02137b8c[];
extern u8 data_02137b98[];

u8 *func_0208fe14(u32 arg0) {
    s32 off;
    u32 idx;

    if (arg0 == 0 || arg0 > 6) {
        return 0;
    }
    idx = arg0 - 1;
    off = data_02137b8c[idx] - 1;
    if (data_02137b98[off] == 0) {
        return 0;
    }
    return data_02137b98 + off;
}
