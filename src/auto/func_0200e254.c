#include "m2c.h"
#include "engine.h"

extern void *data_021372d4;

void func_0200e254(s32 arg0) {
    M2C_FIELD(data_021372d4, s32 *, 4) = (s32) (M2C_FIELD(data_021372d4, s32 *, 4) & ~(1 << arg0));
}
