#include "m2c.h"
#include "engine.h"

extern s32 data_02157340;

void func_020fca88(s32 arg0) {
    data_02157340 &= ~(1 << arg0);
}
