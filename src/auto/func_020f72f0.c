/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020f7b18(M2C_UNK, M2C_UNK, M2C_UNK);

void func_020f72f0(s32 arg0) {
    s32 sp0;
    s32 temp_r1;
    s32 var_r0;
    u8 var_r4;

    temp_r1 = M2C_FIELD(arg0, volatile s32 *, 8);
    if (!(temp_r1 & 0x200) && (temp_r1 & 1)) {
        if (M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x18) != NULL) {
            var_r4 = M2C_FIELD(arg0, volatile u8 *, 0x8F);
        } else {
            var_r4 = 0;
        }
        if (var_r4 == 1) {
            M2C_FIELD(arg0, volatile s32 *, 8) = (s32) (M2C_FIELD(arg0, volatile s32 *, 8) & ~0x40);
            M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x18)(arg0);
            if (M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x18) != NULL) {
                var_r4 = M2C_FIELD(arg0, volatile u8 *, 0x8F);
            } else {
                var_r4 = 0;
            }
            var_r0 = M2C_FIELD(arg0, volatile s32 *, 8) & 0x40;
        } else {
            var_r0 = 0;
        }
        if (var_r0 == 0) {
            sp0 = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 1);
            if (!(M2C_FIELD(arg0, volatile s32 *, 8) & 0x100)) {
                func_020f7b18(0x14, (s32) &sp0, 1);
            }
        }
        if (var_r4 == 3) {
            M2C_FIELD(arg0, volatile s32 *, 8) = (s32) (M2C_FIELD(arg0, volatile s32 *, 8) & ~0x40);
            M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x18)(arg0);
        }
    }
    M2C_FIELD(arg0, void **, 0) = (void *) (M2C_FIELD(arg0, void **, 0) + 2);
}
