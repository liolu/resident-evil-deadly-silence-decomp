/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_0207efb8(void **);
void func_0207efc4(void **);
void func_0207f464(void **);

void func_0207f5c8(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x90);
    switch (temp_r1) {
        case 0:
            func_0207f464(arg0);
        /* fallthrough */
        case 1:
            func_0207efc4(arg0);
            break;
        case 2:
            func_0207efb8(arg0);
            break;
        case 3:
            break;
        default:
            func_0207efb8(arg0);
            break;
    }
}
