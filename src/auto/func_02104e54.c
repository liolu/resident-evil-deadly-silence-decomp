#include "m2c.h"
#include "engine.h"

extern u16 data_02158b6c;

void func_02104e54(s32 arg0) {
    data_02158b6c |= 1 << arg0;
}
