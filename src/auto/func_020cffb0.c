#include "engine.h"
#include "m2c.h"

void func_020c0070(M2C_UNK, M2C_UNK);

extern M2C_UNK data_02126314;

void func_020cffb0(s32 arg0, s32 arg1) {
    func_020c0070(arg0 + 8, *((M2C_UNK *) ((s8 *) &data_02126314 + (arg1 * 4))));
}
