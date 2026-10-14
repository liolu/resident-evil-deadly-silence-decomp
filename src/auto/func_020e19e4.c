/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e0408(s32, s32, s32);               /* extern */
M2C_UNK func_020e0b88(s32, s32);                    /* extern */
M2C_UNK func_020e0bc4(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020e0c98(s32);                         /* extern */
M2C_UNK func_020e0ce8(s32);                         /* extern */
M2C_UNK func_020e0da8(s32, M2C_UNK);                /* extern */
M2C_UNK func_020e0e98(s32);                         /* extern */
M2C_UNK func_020e0f08(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_020e1a90(void *, s32);                 /* extern */
extern s32 data_0212ff6c;

void func_020e19e4(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    func_020e0408(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s16 *, 0x3E) << 0xB, M2C_FIELD(arg0, s16 *, 0x3C) << 0xB);
    func_020e0b88(M2C_FIELD(arg0, s32 *, 8), data_0212ff6c);
    func_020e0bc4(M2C_FIELD(arg0, s32 *, 8), 0, 0);
    func_020e0da8(M2C_FIELD(arg0, s32 *, 8), 0);
    func_020e0c98(M2C_FIELD(arg0, s32 *, 8));
    func_020e0e98(M2C_FIELD(arg0, s32 *, 8));
    func_020e0f08(M2C_FIELD(arg0, s32 *, 8), arg1, arg2, arg3, arg4);
    func_020e0ce8(M2C_FIELD(arg0, s32 *, 8));
    func_020e1a90(arg0, M2C_FIELD(arg0, s32 *, 0x10));
}
