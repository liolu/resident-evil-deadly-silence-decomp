#include "m2c.h"

u16 func_02090b0c(void *arg0) {
    return (u16) ((M2C_FIELD(arg0, s16 *, 0x44) + 0x800) & 0xFFF);
}
