/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02103940();                            /* extern */
s32 func_021054ac();                                /* extern */
M2C_UNK func_021054c0(s32);                         /* extern */
extern void **data_0215888c;

void func_02103b00(u16 *arg0) {
    s32 temp_r4;
    void *temp_r2;

    temp_r4 = func_021054ac();
    temp_r2 = *data_0215888c;
    if (arg0 != NULL) {
        *arg0 |= (u16) (1 << M2C_FIELD(temp_r2, s32 *, 0x6C));
    }
    M2C_FIELD(temp_r2, s32 *, 0x64) = 0;
    func_02103940();
    func_021054c0(temp_r4);
}
