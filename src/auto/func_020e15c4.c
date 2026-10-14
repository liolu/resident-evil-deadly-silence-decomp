/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020deb88(M2C_UNK);

extern M2C_UNK data_0212ff9c;

s32 func_020e15c4(s32 arg0) {
    if (arg0 != 0) {
        return (s32) M2C_FIELD(arg0, s16 *, 0x40);
    }
    func_020deb88((s32) &data_0212ff9c);
    return 0;
}
