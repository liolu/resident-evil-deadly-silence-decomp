/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e40e4(M2C_UNK, M2C_UNK);

extern M2C_UNK data_02130260;
extern M2C_UNK data_0213026c;
extern M2C_UNK data_02130288;
extern M2C_UNK data_02130294;

s32 func_020e3368(s32 arg0) {
    if (arg0 == 0) {
        func_020e40e4((s32) &data_02130260, (s32) &data_0213026c);
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        return M2C_FIELD(arg0, s32 *, 0x20);
    }
    func_020e40e4((s32) &data_02130288, (s32) &data_02130294);
    return 0;
}
