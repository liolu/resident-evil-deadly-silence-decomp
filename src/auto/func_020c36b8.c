/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020b7270(void);
void func_020b842c(M2C_UNK, M2C_UNK);

void func_020c36b8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_020b842c(0xD, arg0);
    }
    if (arg1 != 0) {
        func_020b842c(0xE, arg1);
    }
    func_020b7270();
}
