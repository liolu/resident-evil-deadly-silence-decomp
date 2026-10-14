/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e3130(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020e315c(M2C_UNK, M2C_UNK, M2C_UNK);

void func_020dbf20(s32 arg0) {
    func_020e315c(M2C_FIELD(arg0, s32 *, 8), arg0 + 0xAC, arg0 + 0xB0);
    func_020e3130(M2C_FIELD(arg0, s32 *, 8), arg0 + 0xA6, arg0 + 0xA8, arg0 + 0xAA);
}
