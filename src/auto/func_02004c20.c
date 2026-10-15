#include "engine.h"
#include "m2c.h"

M2C_UNK func_02004be0(void);

extern s8 data_02136ea0;

s32 func_02004c20(void) {
    data_02136ea0 = 0;
    return func_02004be0();
}
