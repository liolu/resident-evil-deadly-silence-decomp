/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e40e4(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213020c;
extern M2C_UNK data_02130218;
extern M2C_UNK data_02130234;
extern M2C_UNK data_02130240;

s32 func_020e32d0(s32 arg0) {
    if (arg0 == 0) {
        func_020e40e4((s32) &data_0213020c, (s32) &data_02130218);
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        return M2C_FIELD(arg0, s32 *, 0x24);
    }
    func_020e40e4((s32) &data_02130234, (s32) &data_02130240);
    return 0;
}
