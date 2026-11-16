/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02102318();
M2C_UNK func_020f430c(void *);
M2C_UNK func_021022a4(void *, s32, s32);
M2C_UNK func_0210224c();

void func_0207609c(void *arg0) {
    s32 r;

    func_02102318();
    M2C_FIELD(arg0, u16 *, 0x32) = M2C_FIELD(arg0, u16 *, 0x32) | 1;
    r                            = func_020f430c(arg0);
    func_021022a4((u8 *) arg0 + M2C_FIELD(arg0, s32 *, 0x38), (M2C_FIELD(arg0, s32 *, 0x2C) & 0xFFFF) << 3, r);
    func_0210224c();
}
