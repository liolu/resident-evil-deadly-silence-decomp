/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020b6b5c(void);
void func_020b8110(M2C_UNK, M2C_UNK);

void func_02013c48(void) {
    s32 var_r0;

    if (func_020b6b5c() != 0) {
        var_r0 = 0x12;
    } else {
        var_r0 = 7;
    }
    func_020b8110(var_r0, 0);
}
