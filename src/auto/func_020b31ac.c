/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200ed94();                            /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern s32 data_0213daa8;

s32 func_020b31ac(void) {
    data_0213daa8 += 2;
    M2C_FIELD(&data_0213ad98, u8 *, 2) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 4);
    func_0200ed94();
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & ~0x100000);
    return 1;
}
