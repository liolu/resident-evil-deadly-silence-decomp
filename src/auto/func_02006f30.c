/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern void *data_02137298;

s32 func_02006f30(void) {
    if (M2C_FIELD(data_02137298, u8 *, 0x3EAA) & 1) {
        return 1;
    }
    return 0;
}
