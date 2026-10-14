/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02058b4c(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x30) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2);
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x34) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 4);
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x38) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 6);
    return 8;
}
