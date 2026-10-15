/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e40e4(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213059c;
extern M2C_UNK data_021305a8;
extern M2C_UNK data_021305c4;
extern M2C_UNK data_021305d0;

s32 func_020e3de4(s32 arg0) {
    if (arg0 == 0) {
        func_020e40e4((s32) &data_0213059c, (s32) &data_021305a8);
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        return M2C_FIELD(arg0, s32 *, 8);
    }
    func_020e40e4((s32) &data_021305c4, (s32) &data_021305d0);
    return 0;
}
