/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020f7c14(M2C_UNK, M2C_UNK);

void func_020f6d28(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r0;
    u8 var_r4;

    if (M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x20) != NULL) {
        var_r4 = M2C_FIELD(arg0, u8 *, 0x91);
    } else {
        var_r4 = 0;
    }
    if (var_r4 == 1) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~0x40);
        M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x20)(arg0);
        if (M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x20) != NULL) {
            var_r4 = M2C_FIELD(arg0, u8 *, 0x91);
        } else {
            var_r4 = 0;
        }
        var_r0 = M2C_FIELD(arg0, s32 *, 8) & 0x40;
    } else {
        var_r0 = 0;
    }
    if ((var_r0 == 0) && !(M2C_FIELD(arg0, s32 *, 8) & 0x100)) {
        func_020f7c14(arg2 + M2C_FIELD(arg2, s32 *, 8), M2C_FIELD(arg2, s32 *, 0xC));
    }
    if (var_r4 == 2) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~0x40);
        M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x20)(arg0);
        if (M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x20) != NULL) {
            var_r4 = M2C_FIELD(arg0, u8 *, 0x91);
        } else {
            var_r4 = 0;
        }
    }
    if (var_r4 != 3) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~0x40);
    M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x20)(arg0);
}
