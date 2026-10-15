#include "engine.h"
#include "m2c.h"

void func_020ff68c(M2C_UNK);

extern M2C_UNK data_021587ec;

void func_020ff61c(void) {
    *(s32 *) 0x04000000 &= ~0x80000000;
    func_020ff68c((s32) &data_021587ec);
}
