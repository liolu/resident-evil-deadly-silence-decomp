#include "engine.h"
#include "m2c.h"

void func_020ff1e8(s32 arg0) {
    *(s32 *) 0x04001000 = (*(s32 *) 0x04001000 & ~7) | arg0;
}
