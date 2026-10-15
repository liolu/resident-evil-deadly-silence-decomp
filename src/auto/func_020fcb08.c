/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_021066fc(M2C_UNK, M2C_UNK);

extern s32 data_02157344;

void func_020fcb08(s32 arg0) {
    if (arg0 == 0) {
        return;
    }
    func_021066fc(arg0, 0);
    data_02157344 &= ~arg0;
}
