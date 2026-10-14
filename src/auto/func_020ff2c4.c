/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern s16 data_02136b88;
extern s16 data_021587d8;

void func_020ff2c4(void) {
    s32 temp_ip;

    temp_ip = *(s32 *)0x04000000;
    data_02136b88 = 0;
    data_021587d8 = (s16) ((u32) (temp_ip & 0x30000) >> 0x10);
    *(s32 *)0x04000000 = temp_ip & ~0x30000;
}
