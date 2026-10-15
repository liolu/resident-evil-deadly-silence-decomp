/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_027e01ac;

void func_0200f930(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(&data_027e01ac, s16 *, 0x82) = (s16) (((arg0 << 8) & 0xFF00) | (u8) arg2);
    M2C_FIELD(&data_027e01ac, s16 *, 0x86) = (s16) (((arg1 << 8) & 0xFF00) | (u8) arg3);
}
