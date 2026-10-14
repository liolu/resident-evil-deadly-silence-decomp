#include "m2c.h"
#include "engine.h"

void func_0210fb3c(s32 arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((s32) (*(u16 *)0x04000204 & 0xC) >> 2);
    M2C_FIELD(arg0, s32 *, 4) = (s32) ((s32) (*(u16 *)0x04000204 & 0x10) >> 4);
    *(u16 *)0x04000204 = (*(u16 *)0x04000204 & ~0xC) | 0xC;
    *(u16 *)0x04000204 &= ~0x10;
}
