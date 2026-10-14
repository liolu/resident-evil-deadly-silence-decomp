/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02006fb4(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_02103a58(void *);                      /* extern */
M2C_UNK func_02103c54(void *, M2C_UNK *, M2C_UNK, void *, s32, s32); /* extern */
M2C_UNK func_02105324(void *);                      /* extern */
M2C_UNK func_02105334();                            /* extern */
M2C_UNK func_0210ab9c();                            /* extern */
extern void *data_02137298;
extern M2C_UNK func_02007184;

s32 func_02006e3c(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 var_r0;

    func_0210ab9c();
    M2C_FIELD(data_02137298, s32 *, 0x3EB8) = arg0;
    M2C_FIELD(data_02137298, s32 *, 0x3EBC) = arg1;
    func_02105334();
    func_02105324(data_02137298 + 0x3EC0);
    func_02103c54(data_02137298 + 0x1CEC, &func_02007184, 0, data_02137298 + 0x3980, 0x400, 0xA);
    func_02103a58(data_02137298 + 0x1CEC);
    func_02006fb4(arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    if (M2C_FIELD(data_02137298, u8 *, 0x3EA8) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return 0 - var_r0;
}
