/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_02147cc0;

s32 func_02074ef0(s32 arg0) {
    s32 i;
    u8 *tbl;
    s32 n;

    if (arg0 == 0) {
        return -1;
    }
    tbl = M2C_FIELD(&data_02147cc0, u8 **, 0x538);
    n   = M2C_FIELD(&data_02147cc0, u8 *, 0x540);
    i   = 0;
    goto test;
body:
    if (arg0 == tbl[i * 2]) {
        return i;
    }
    i++;
test:
    if (i < n) {
        goto body;
    }
    return -1;
}
