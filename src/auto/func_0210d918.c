#include "m2c.h"
#include "engine.h"

extern u16 data_0215b1a8;

s32 func_0210d918(void) {
    if (data_0215b1a8 != 0) {
        return 0;
    }
    return 3;
}
