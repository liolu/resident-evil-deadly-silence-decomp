/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02105714(M2C_UNK *);                   /* extern */
M2C_UNK func_021060a4(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_021061d8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0213caa0;
extern M2C_UNK data_0213cff8;
extern M2C_UNK data_02141cc0;

void func_020d94b0(void) {
    volatile s32 sp0;

    sp0 = 0;
    func_021060a4(sp0, &data_0213caa0, 0x720);
    M2C_FIELD(&data_0213caa0, s8 *, 0x701) = 1;
    func_021061d8(&data_02141cc0, 0, 0x2000);
    M2C_FIELD(&data_02141cc0, s32 *, 0x40) = 0;
    func_02105714(&data_0213cff8);
}
