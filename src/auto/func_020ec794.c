#include "m2c.h"

void func_020ec794(u8 *arg0, u8 *arg1) {
    u16 v;
    v                     = (u16) ((arg0[2] << 8) | arg0[3]);
    *(u16 *) (arg1 + 0xE) = v;
}
