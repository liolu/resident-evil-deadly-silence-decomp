/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e03b0(void);
void func_020e03bc(void);

void func_020e0eb8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_020e03bc();
    M2C_FIELD(arg0, s32 *, 0xC) = arg3;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (arg4 << 0xB);
    M2C_FIELD(arg0, s32 *, 0x14) = arg4;
    M2C_FIELD(arg0, s32 *, 0x50) = arg1;
    M2C_FIELD(arg0, s32 *, 0x54) = arg2;
    M2C_FIELD(arg0, s8 *, 0x45) = 1;
    func_020e03b0();
}
