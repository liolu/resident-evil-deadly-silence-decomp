/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02106728(M2C_UNK, M2C_UNK);

extern s32 data_02157344;

s32 func_020fcb40(s32 arg0) {
    if (arg0 == 0) {
        return 1;
    }
    if (arg0 & data_02157344) {
        return 0;
    }
    func_02106728(arg0, 0);
    data_02157344 |= arg0;
    return 1;
}
