/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02102aa8(void);
M2C_UNK func_02102b98(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void func_02102cc8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_02102b98(arg0, arg1, arg2, arg3) <= 0) {
        return;
    }
    do {
        func_02102aa8();
    } while (func_02102b98(arg0, arg1, arg2, arg3) > 0);
}
