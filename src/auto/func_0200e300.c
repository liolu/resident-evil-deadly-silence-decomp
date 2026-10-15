/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern void *data_021372d4;
extern void *data_021372d8;

void func_0200e300(void) {
    data_021372d4                           = data_021372d8 + 0x4354;
    M2C_FIELD(data_021372d8, s32 *, 0x4354) = 0;
    M2C_FIELD(data_021372d4, s32 *, 4)      = 0;
    M2C_FIELD(data_021372d4, s32 *, 8)      = 0;
}
