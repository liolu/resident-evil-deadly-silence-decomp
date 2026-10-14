/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02102810(M2C_UNK);                     /* extern */
M2C_UNK func_021029a0(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_02104e54(M2C_UNK);                     /* extern */
extern u16 data_02158b70;
extern s32 data_02158b74;
extern M2C_UNK data_02158b78;
extern M2C_UNK func_02104f20;

void func_02104fa8(void) {
    if (data_02158b70 != 0) {
        return;
    }
    data_02158b70 = 1;
    func_02104e54(0);
    M2C_FIELD(&data_02158b78, s32 *, 0) = 0;
    M2C_FIELD(&data_02158b78, s32 *, 4) = 0;
    *(s16 *)0x04000102 = 0;
    *(s16 *)0x04000100 = 0;
    *(s16 *)0x04000102 = 0xC1;
    func_021029a0(8, &func_02104f20);
    func_02102810(8);
    data_02158b74 = 0;
}
