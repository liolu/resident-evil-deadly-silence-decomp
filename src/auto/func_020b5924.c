#include "m2c.h"

extern M2C_UNK data_02122ef0;

u16 func_020b5924(s32 arg0) {
    return *((u16 *) ((s8 *) &data_02122ef0 + (arg0 * 4)));
}
