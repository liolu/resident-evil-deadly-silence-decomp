/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021374cc;

void func_02085f44(s32 arg0) {
    M2C_FIELD(&data_021374cc, s16 *, 0x34) = (s16) arg0;
    M2C_FIELD(&data_021374cc, s32 *, 0x24) = (s32) (M2C_FIELD(&data_021374cc, s32 *, 0x24) + arg0);
    M2C_FIELD(&data_021374cc, s32 *, 0xC)  = (s32) (M2C_FIELD(&data_021374cc, s32 *, 0xC) + arg0);
    M2C_FIELD(&data_021374cc, u16 *, 0xA)  = (u16) (M2C_FIELD(&data_021374cc, u16 *, 0xA) + 1);
}
