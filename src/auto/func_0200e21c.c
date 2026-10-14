/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_021066fc(M2C_UNK, M2C_UNK);

extern s32 *data_021372d4;

void func_0200e21c(s32 arg0) {
    *data_021372d4 &= ~arg0;
    func_021066fc(arg0, 0);
}
