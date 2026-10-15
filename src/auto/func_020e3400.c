/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e40e4(M2C_UNK, M2C_UNK);

extern M2C_UNK data_021302b4;
extern M2C_UNK data_021302c0;
extern M2C_UNK data_021302dc;
extern M2C_UNK data_021302e8;

s32 func_020e3400(s32 arg0) {
    if (arg0 == 0) {
        func_020e40e4((s32) &data_021302b4, (s32) &data_021302c0);
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        return M2C_FIELD(arg0, s32 *, 0x1C);
    }
    func_020e40e4((s32) &data_021302dc, (s32) &data_021302e8);
    return 0;
}
