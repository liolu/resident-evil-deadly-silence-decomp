/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_0211851c(M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_0205126c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    M2C_FIELD(data_027e000c, s32 *, 0x17C) = func_0211851c((arg2 - arg0) << 0x10, (s32) arg4);
    M2C_FIELD(data_027e000c, s32 *, 0x180) = func_0211851c((arg3 - arg1) << 0x10, (s32) arg4);
}
