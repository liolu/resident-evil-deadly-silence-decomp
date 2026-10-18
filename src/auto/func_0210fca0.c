/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK CpuSet(s32 *, M2C_UNK *, s32);              /* extern */
s16 func_02102a50();                                /* extern */
extern M2C_UNK data_0215bcc0;

void func_0210fca0(void) {
    s32 sp0;

    sp0 = 0;
    CpuSet(&sp0, &data_0215bcc0, 0x05000001);
    M2C_FIELD(&data_0215bcc0, s16 *, 2) = func_02102a50();
}
