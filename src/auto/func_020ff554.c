#include "m2c.h"
#include "engine.h"

void func_020ff68c(M2C_UNK);

extern M2C_UNK data_021587f4;

void func_020ff554(void) {
    *(s32 *)0x04001000 &= ~0x80000000;
    func_020ff68c((s32) &data_021587f4);
}
