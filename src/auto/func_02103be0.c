/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02103940();                            /* extern */
M2C_UNK func_02103a8c(void *);                      /* extern */
M2C_UNK func_02103edc(void *);                      /* extern */
M2C_UNK func_021044d0(void *);                      /* extern */
M2C_UNK func_02105528();                            /* extern */
extern void **data_0215888c;
extern M2C_UNK data_021588a8;

void func_02103be0(void) {
    void *temp_r4;

    temp_r4 = *data_0215888c;
    func_021044d0(temp_r4);
    func_02103edc(temp_r4);
    *((M2C_UNK *) ((s8 *) &data_021588a8 + (M2C_FIELD(temp_r4, s32 *, 0x6C) * 4))) = 0;
    M2C_FIELD(temp_r4, s32 *, 0x64)                                                = 2;
    func_02103a8c(temp_r4 + 0x90);
    func_02103940();
    func_02105528();
}
