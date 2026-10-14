/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_0201fda4(M2C_UNK, M2C_UNK, M2C_UNK);

void func_0201fe54(s32 arg0) {
    func_0201fda4(arg0, 0x258, 0x10);
    if (M2C_FIELD(arg0, u16 *, 0x198) & 0x10) {
        M2C_FIELD(arg0, s8 *, 0x92) = 0;
    }
}
