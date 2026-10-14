/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02058bbc(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0x48) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s8 *, 1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0x4A) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s8 *, 2);
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0x4C) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s8 *, 3);
    return 4;
}
