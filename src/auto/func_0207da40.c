/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02082e2c(void **);
void func_02082f64(void **);
void func_020834dc(void **);
void func_020834cc(void **);

void func_0207da40(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {
        case 0:
            M2C_FIELD(*arg0, u8 *, 0x93) = 0x1C;
            func_02082e2c(arg0);
        /* fallthrough */
        case 1:
            func_02082f64(arg0);
            break;
        case 2:
            func_020834dc(arg0);
            break;
        case 3:
            func_020834cc(arg0);
            break;
    }
}
