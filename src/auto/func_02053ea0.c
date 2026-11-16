/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_021060a4(s32, M2C_UNK *, s32);
extern M2C_UNK data_02144cc0;
extern M2C_UNK data_02144da8;
extern M2C_UNK data_0214813c;

void func_02053ea0(void) {
    volatile s32 sp0;
    volatile s32 sp4;

    sp0                                   = 0;
    M2C_FIELD(&data_02144cc0, s8 *, 0xE5) = 0;
    func_021060a4(sp0, &data_0214813c, 0xBC);
    sp4 = 0;
    func_021060a4(sp4, &data_02144da8, 0x3048);
}
