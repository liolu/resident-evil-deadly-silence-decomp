#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0215444c;

void func_020f4c90(s32 arg0, s32 arg1) {
    *((M2C_UNK *) ((s8 *) &data_0215444c + (arg0 * 4))) = arg1 | (arg0 << 0x1E);
}
