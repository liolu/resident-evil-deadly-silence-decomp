/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_0208358c(void *, u32);
void func_020835ec(void *);
void func_02083670(void);
void func_02083748(void);

void func_020838ec(void **arg0) {
    void *temp_r3;

    switch (M2C_FIELD(*arg0, u8 *, 0x90)) {
        case 0:
            func_02083748();
            break;
        case 1:
            func_02083670();
            temp_r3 = *arg0;
            if (M2C_FIELD(temp_r3, u8 *, 0x91) == 5) {
                M2C_FIELD(temp_r3, u8 *, 0x90) = 2U;
                func_0208358c(arg0, 0xA);
            }
            break;
        case 2:
            func_020835ec(arg0);
            break;
        case 3:
            break;
        default:
            func_020835ec(arg0);
            break;
    }
}
