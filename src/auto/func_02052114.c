/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_0211851c(M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_02052114(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4) {
    M2C_FIELD(data_027e000c, s32 *, 0x17C) = func_0211851c((arg2 - arg0) << 0x10, (s32) arg4);
    M2C_FIELD(data_027e000c, s32 *, 0x184) = func_0211851c((arg3 - arg1) << 0x10, (s32) arg4);
    M2C_FIELD(data_027e000c, s32 *, 0x188) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x30) << 0x10);
    M2C_FIELD(data_027e000c, s32 *, 0x190) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x38) << 0x10);
}
