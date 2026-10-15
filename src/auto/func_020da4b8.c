/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020da4ec(M2C_UNK);
void func_020da624(M2C_UNK);

void func_020da4b8(s32 arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x9C) == 1) {
        func_020da4ec(arg0);
        return;
    }
    func_020da624(arg0);
}
