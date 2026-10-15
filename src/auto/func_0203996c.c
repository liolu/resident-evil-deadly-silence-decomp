#include "engine.h"
#include "m2c.h"

void func_02035b4c(void);

extern void *data_027e000c;

void func_0203996c(void) {
    if (M2C_FIELD(data_027e000c, u8 *, 0x93) == 0) {
        M2C_FIELD(data_027e000c, s8 *, 0x187) = 0xA;
    }
    func_02035b4c();
}
