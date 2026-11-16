/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_0207d240(void **);
void func_0207d24c(void **);
void func_0207d690(void **);

void func_0207d850(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x90);
    switch (temp_r1) {
        case 0:
            func_0207d690(arg0);
        /* fallthrough */
        case 1:
            func_0207d24c(arg0);
            break;
        case 2:
            func_0207d240(arg0);
            break;
        case 3:
            break;
        default:
            func_0207d240(arg0);
            break;
    }
}
