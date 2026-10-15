/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020f7c14(M2C_UNK, M2C_UNK);

void func_020f5a40(s32 arg0) {
    s32 var_r1;
    u8 var_r4;
    void *temp_r0;

    if (M2C_FIELD(arg0, M2C_UNK(**)(s32), 0x34) != NULL) {
        var_r4 = M2C_FIELD(arg0, u8 *, 0x96);
    } else {
        var_r4 = 0;
    }
    if (var_r4 == 1) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~0x40);
        M2C_FIELD(arg0, M2C_UNK(**)(s32), 0x34)(arg0);
        if (M2C_FIELD(arg0, M2C_UNK(**)(s32), 0x34) != NULL) {
            var_r4 = M2C_FIELD(arg0, u8 *, 0x96);
        } else {
            var_r4 = 0;
        }
        var_r1 = M2C_FIELD(arg0, s32 *, 8) & 0x40;
    } else {
        var_r1 = 0;
    }
    if (!(M2C_FIELD(arg0, s32 *, 8) & 0x100) && (var_r1 == 0)) {
        temp_r0 = M2C_FIELD(arg0, void **, 0);
        func_020f7c14((s32) (temp_r0 + (M2C_FIELD(temp_r0, u8 *, 1) | (M2C_FIELD(temp_r0, u8 *, 2) << 8) |
                                        (M2C_FIELD(temp_r0, u8 *, 3) << 0x10) | (M2C_FIELD(temp_r0, u8 *, 4) << 0x18))),
                      M2C_FIELD(temp_r0, u8 *, 5) | (M2C_FIELD(temp_r0, u8 *, 6) << 8) |
                          (M2C_FIELD(temp_r0, u8 *, 7) << 0x10) | (M2C_FIELD(temp_r0, u8 *, 8) << 0x18));
    }
    if (var_r4 == 3) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~0x40);
        M2C_FIELD(arg0, M2C_UNK(**)(s32), 0x34)(arg0);
    }
    M2C_FIELD(arg0, void **, 0) = (void *) (M2C_FIELD(arg0, void **, 0) + 9);
}
