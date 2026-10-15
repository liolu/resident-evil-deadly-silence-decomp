/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020fd278(void *, M2C_UNK, s32, s32, s32, s32, M2C_UNK *, void *); /* extern */
extern M2C_UNK func_020e8bcc;

void func_020e8c0c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    func_020fd278(arg0 + 0x24, 1, M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0xC), M2C_FIELD(arg0, s32 *, 0x10), 4,
                  &func_020e8bcc, arg0);
}
