/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02100adc(M2C_UNK, M2C_UNK, s32, M2C_UNK, s32); /* extern */
M2C_UNK func_02100b9c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_0200fb98(void) {
    *(u16 *) 0x04000060 &= 0xCFFB;
    *(u16 *) 0x04000060 = (*(u16 *) 0x04000060 & ~0x3000) | 8;
    *(u16 *) 0x04000060 &= 0xCFDF;
    *(u16 *) 0x04000060 = (*(u16 *) 0x04000060 & ~0x3000) | 0x10;
    *(u16 *) 0x04000060 &= 0xFFFFCFFD;
    func_02100b9c(0, 0, 0, 0);
    func_02100adc(0, 0, 0x7FFF, 0x3F, 0);
    *(s32 *) 0x04000580 = 0xBFFF0000;
}
