#include "m2c.h"
#include "engine.h"

void func_020ba93c(void);

extern void *data_027e000c;

void func_020baf38(void) {
    M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
    func_020ba93c();
}
