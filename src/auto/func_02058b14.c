/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02058b14(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0x42) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2);
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0x44) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 4);
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0x46) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 6);
    return 8;
}
