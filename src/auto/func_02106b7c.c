/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0210551c(M2C_UNK);
M2C_UNK func_02106aa8(void);
void func_02106be8(M2C_UNK, M2C_UNK);
M2C_UNK func_02107cf0(M2C_UNK, M2C_UNK);
void func_02107d18(M2C_UNK, M2C_UNK);

void func_02106b7c(void) {
    func_02107d18(7, (s32) func_02106be8);
    if (func_02106aa8() == 0) {
        return;
    }
    if (func_02107cf0(7, 1) != 0) {
        return;
    }
    do {
        func_0210551c(0x64);
    } while (func_02107cf0(7, 1) == 0);
}
