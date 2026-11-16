#include "m2c.h"

void func_0207e8d4(void *arg0) {
    M2C_FIELD(arg0, u8 *, 7)                           = (u8) (M2C_FIELD(arg0, u8 *, 7) & ~0x10);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x92) = 0xFF;
}
