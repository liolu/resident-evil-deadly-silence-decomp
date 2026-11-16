/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_021486e0;
extern M2C_UNK data_0214bcc0;
M2C_UNK func_021060a4(s32, M2C_UNK *, M2C_UNK);

void func_02014e5c(void) {
    volatile s32 sp0;

    sp0                                    = 0;
    M2C_FIELD(&data_0214bcc0, s8 *, 0x7A2) = 0;
    func_021060a4(sp0, &data_021486e0, 0x2C0);
}
