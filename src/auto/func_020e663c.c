/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK VBlankIntrWait();                           /* extern */
M2C_UNK func_020e5f14();                            /* extern */
M2C_UNK func_02103a58(M2C_UNK *);                   /* extern */
M2C_UNK func_02103b00(M2C_UNK);                     /* extern */
extern M2C_UNK data_0215301c;
extern M2C_UNK data_02153054;
extern M2C_UNK data_021531a4;

void func_020e663c(void) {
    if ((u32) M2C_FIELD(&data_02153054, u32 *, 0x24) <= 1U) {
        VBlankIntrWait();
        return;
    }
    if (M2C_FIELD(&data_02153054, u32 *, 0x24) != 2) {
        return;
    }
    func_020e5f14();
    M2C_FIELD(&data_0215301c, s32 *, 0x10) = 0;
    func_02103a58(&data_021531a4);
    func_02103b00(0);
}
