/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02004618();                                /* extern */
s32 func_02004950();                                /* extern */
M2C_UNK func_02071378(u8, M2C_UNK, u8);             /* extern */
M2C_UNK func_020af6f4(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;

void func_020b0850(void) {
    func_02071378(M2C_FIELD(&data_0213b890, u8 *, 0x1E), 0, (u8) M2C_FIELD(&data_0213b890, s32 *, 0x2C));
    if (func_02004950() != 0) {
        M2C_FIELD(&data_0213b2b4, s8 *, 0xA) = 3;
        return;
    }
    if (func_02004618() == 0) {
        func_020af6f4(2, 4, 0x60);
        func_020c4798(6);
        return;
    }
    func_020c4798(7);
}
