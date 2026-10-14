/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02104230(void);
M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);

s32 func_02106aa8(void) {
    s32 temp_r0;
    s32 temp_r4;

    if (func_02104230() == 0) {
        return 1;
    }
    temp_r0 = func_021054ac();
    *(s32 *)0x04FFF200 = 0x10;
    temp_r4 = *(s32 *)0x04FFF200;
    func_021054c0(temp_r0);
    if (temp_r4 != 0) {
        return 1;
    }
    return 0;
}
