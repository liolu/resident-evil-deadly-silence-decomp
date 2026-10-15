/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020fa794(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void func_020fa688(s32 arg0, s32 arg1, s32 arg2) {
    func_020fa794(M2C_FIELD(arg1, s32 *, 8), (s32) (u16) arg2, (s32) M2C_FIELD(arg1, s32 *, 0) >> 0xC, arg0);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) & ~0xC0000000);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) | 0x40000000);
    M2C_FIELD(arg0, s32 *, 0)    = (s32) (M2C_FIELD(arg0, s32 *, 0) | 8);
}
