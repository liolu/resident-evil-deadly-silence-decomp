/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02106448(s32, s32, s32, s32);             /* extern */
void func_0210cfe0(s32, s32);                       /* extern */
extern M2C_UNK data_0215a960;
extern M2C_UNK data_0215af80;

void func_0210cf88(void) {
    s32 *base;
    s32 temp_r1;

    base = (s32 *) &data_0215a960;
    func_02106448(base[9], 0x04100010, base[7], 0x200);
    temp_r1 = base[6];
    func_0210cfe0(((u32) temp_r1 >> 8) | 0xB7000000, temp_r1 << 24);
    *(volatile s32 *) 0x040001A4 = ((s32 *) &data_0215af80)[1];
}
