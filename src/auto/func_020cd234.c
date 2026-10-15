#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020cd234(s32 arg0, s32 arg1) {
    u8 temp_r3;
    void *temp_ip;

    temp_ip                     = M2C_FIELD(&data_0213b890, s32 *, 0x4C) + arg1;
    temp_r3                     = M2C_FIELD(temp_ip, u8 *, 8);
    M2C_FIELD(temp_ip, u8 *, 8) = (u8) M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + arg0), u8 *, 8);
    M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + arg0), u8 *, 8) = temp_r3;
}
