#include "engine.h"
#include "m2c.h"

void func_0202be2c(void);

extern void *data_027e000c;

void func_0202f834(void) {
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0;
    func_0202be2c();
}
