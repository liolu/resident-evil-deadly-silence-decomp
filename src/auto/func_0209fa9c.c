/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b2b4;

void func_0209fa9c(s32 arg0) {
    M2C_FIELD(&data_0213b2b4, s8 *, 0xB4)    = (s8) arg0;
    M2C_FIELD(&data_0213b2b4, s8 *, 0xB5)    = 0;
    *M2C_FIELD(&data_0213b2b4, s32 **, 0xB8) = 0;
}
