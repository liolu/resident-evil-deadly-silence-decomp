/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02154424;

void func_020f4ca4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    *((M2C_UNK *)((s8 *)&data_02154424 + (arg0 * 4))) = (0x3FF & (arg1 >> 3)) | ((0x3FF & (arg2 >> 3)) << 0xA) | ((0x3FF & (arg3 >> 3)) << 0x14) | (arg0 << 0x1E);
}
