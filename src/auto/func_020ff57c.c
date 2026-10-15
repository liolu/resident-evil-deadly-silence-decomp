#include "engine.h"
#include "m2c.h"

void func_020ff68c(M2C_UNK);

extern M2C_UNK data_021587f2;

void func_020ff57c(void) {
    *(s32 *) 0x04001000 &= ~0x40000000;
    func_020ff68c((s32) &data_021587f2);
}
