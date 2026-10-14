/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e9c9c(M2C_UNK, M2C_UNK);
void func_020ec408(M2C_UNK);
void func_020ecc24(M2C_UNK, M2C_UNK);

void func_020ec224(s32 arg0) {
    func_020ec408(arg0);
    func_020ecc24(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 0x10));
    func_020e9c9c(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4));
    M2C_FIELD(arg0, s8 *, 9) = 1;
}
