#include "m2c.h"

void func_0207f8bc(u8 *arg0) {
    s8 *p;
    arg0[7]          = arg0[7] & ~0x10;
    p                = *(s8 **) arg0;
    ((u8 *) p)[0x92] = 0xFF;
}
