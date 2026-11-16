#include "m2c.h"

extern u8 data_02144da8[];
extern u8 data_02147cc0[];
extern u8 data_0214813d[];
extern u8 data_0214813f[];

s32 func_02053c74(void *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    if (data_02147cc0[0x47C] == 0) {
        return 0;
    }
    return (s32) data_02144da8 + data_0214813d[data_0214813f[((s8 *) arg0)[6] * 4] * 4] * 0x19C;
}
