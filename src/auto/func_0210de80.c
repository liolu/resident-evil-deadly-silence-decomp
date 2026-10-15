/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0210469c(M2C_UNK, M2C_UNK);
M2C_UNK func_0210d918(void);
M2C_UNK func_0210d934(void);

s32 func_0210de80(void) {
    s32 temp_r2;
    s32 temp_r4;
    u16 temp_r0;

    temp_r4 = func_0210d934();
    if (func_0210d918() != 0) {
        return 0;
    }
    func_0210469c(M2C_FIELD(temp_r4, s32 *, 4), 2);
    temp_r2 = M2C_FIELD(temp_r4, s32 *, 4);
    temp_r0 = M2C_FIELD(temp_r2, u16 *, 0);
    switch (temp_r0) {                              /* irregular */
        case 9:
            func_0210469c(temp_r2 + 0x17E, 2);
            if (M2C_FIELD(M2C_FIELD(temp_r4, s32 *, 4), u16 *, 0x17E) == 0) {
                return 0;
            }
        case 10:
        case 11:
            func_0210469c(M2C_FIELD(temp_r4, s32 *, 4) + 0xB8, 2);
            return (s32) M2C_FIELD(M2C_FIELD(temp_r4, s32 *, 4), u16 *, 0xB8);
        default:
            return 0;
    }
}
