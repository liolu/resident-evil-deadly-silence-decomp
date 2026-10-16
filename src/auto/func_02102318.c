/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020ff798();                                /* extern */
extern M2C_UNK data_0212bcf8;
extern s32 data_0215880c;
extern s32 data_02158810;

void func_02102318(void) {
    s32 temp_r0;

    temp_r0       = func_020ff798();
    data_02158810 = temp_r0;
    data_0215880c = *((u16 *) ((s8 *) &data_0212bcf8 + ((temp_r0 >> 4) * 2))) << 0xC;
}
