#include "m2c.h"
#include "engine.h"

void func_0202c120(void);

extern void *data_027e000c;

void func_0202f854(void) {
    M2C_FIELD(data_027e000c, s8 *, 0xA1) = 0x1B;
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0;
    func_0202c120();
}
