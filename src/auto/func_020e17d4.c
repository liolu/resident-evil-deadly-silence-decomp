/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020deb88(M2C_UNK);
M2C_UNK func_020df358(M2C_UNK);

extern M2C_UNK data_0213004c;

s32 func_020e17d4(s32 arg0) {
    if (arg0 == 0) {
        func_020deb88((s32) &data_0213004c);
        return -1;
    }
    if ((s32) M2C_FIELD(arg0, s8 *, 1) < 2) {
        return 0;
    }
    return func_020df358(M2C_FIELD(arg0, s32 *, 4));
}
