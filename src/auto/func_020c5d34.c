/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c5d34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_ip;

    temp_ip                                                                    = arg0 * 0x1C;
    M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + temp_ip), s16 *, 0x56) = (s16) arg1;
    M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + temp_ip), s16 *, 0x58) = (s16) arg2;
    M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + temp_ip), s16 *, 0x60) = 0x7F;
    M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + temp_ip), s16 *, 0x62) = 0;
    M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + temp_ip), s32 *, 0x50) = arg3;
    M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + temp_ip), s8 *, 0x5F)  = 0;
}
