/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_021060a4(s32, M2C_UNK *, M2C_UNK);
M2C_UNK func_021061d8(M2C_UNK *, M2C_UNK, M2C_UNK);
extern M2C_UNK data_0214852c;
extern M2C_UNK data_021489a0;
extern M2C_UNK data_0214bcc0;

void func_02017e84(void) {
    volatile s32 sp0;

    func_021061d8(&data_021489a0, 0, 0x3AC0);
    sp0                                    = 0;
    M2C_FIELD(&data_0214bcc0, s8 *, 0x7A0) = 0x50;
    func_021060a4(sp0, &data_0214852c, 0x190);
}
