/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_021060a4(s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK data_0213e394;
extern M2C_UNK data_0213e3e8;

void func_02091f68(void) {
    volatile s32 sp0;

    sp0                                   = 0;
    M2C_FIELD(&data_0213e394, s8 *, 0x2E) = 1;
    func_021060a4(sp0, &data_0213e3e8, 0xF00);
}
