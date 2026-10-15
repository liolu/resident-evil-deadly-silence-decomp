/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02091514(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (s16) (arg1 * 9);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (s16) (arg2 * 9);
}
