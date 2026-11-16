/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213b890;
extern u8 data_0213ad48;
void func_020c47b8(void);
void func_0206fcf8(s32, s32, s32, s32);
void func_020ae3c8(s32);

void func_020ae30c(void) {
    s32 var_r0;

    func_020c47b8();
    data_0213b890 = 1;
    func_0206fcf8(4, 2, 1, 0x1000);
    *(volatile u16 *) 0x04000304 = (u16) (*(volatile u16 *) 0x04000304 & ~0x8000);
    switch (M2C_FIELD(&data_0213ad48, u8 *, 1)) {
        case 0:
        case 1:
        case 2:
        case 3:
            var_r0 = 1;
            break;
        case 4:
        default:
            var_r0 = 2;
            break;
    }
    func_020ae3c8(var_r0);
}
