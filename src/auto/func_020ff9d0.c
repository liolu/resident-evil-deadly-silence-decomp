#include "m2c.h"
#include "engine.h"

void func_02100220(M2C_UNK);

extern u16 data_021587dc;

void func_020ff9d0(s32 arg0) {
    data_021587dc |= arg0;
    func_02100220(arg0);
}
