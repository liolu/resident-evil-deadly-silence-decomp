#include "m2c.h"

void func_02003b00(u32 arg0) {
    volatile u32 *reg = (volatile u32 *) 0x04000000;
    u32 hi            = *reg & 0x1F00;
    u32 lo            = *reg & ~0x1F00;
    *reg              = lo | ((arg0 | (hi >> 8)) << 8);
}
