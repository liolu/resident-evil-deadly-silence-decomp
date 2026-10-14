#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0212f744;
extern M2C_UNK data_0212fa08;

s32 func_020d8880(s32 arg0) {
    if ((u32) arg0 < 0x17U) {
        return *((M2C_UNK *)((s8 *)&data_0212fa08 + (arg0 * 4)));
    }
    return (s32) &data_0212f744;
}
