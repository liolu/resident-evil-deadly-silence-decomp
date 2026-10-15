#include "engine.h"
#include "m2c.h"

void func_02084c40(s32 arg0, s32 arg1) {
    void *temp_ip;

    temp_ip                         = *(M2C_UNK *) arg0;
    M2C_FIELD(temp_ip, s16 *, 0x44) = (s16) ((M2C_FIELD(temp_ip, s16 *, 0x44) + (s16) (arg1 & 0xFFF)) & 0xFFF);
}
