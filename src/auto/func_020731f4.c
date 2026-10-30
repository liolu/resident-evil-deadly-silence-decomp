/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02072ef8(s16);                         /* extern */
M2C_UNK func_02090954(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad48;

void func_020731f4(void *arg0) {
    func_02072ef8(M2C_FIELD(arg0, s16 *, 0x12));
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) (M2C_FIELD(arg0, s16 *, 0x10) + 1);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x10) > 0x30) {
        M2C_FIELD(arg0, s8 *, 1) = 5;
        func_0206fcf8(0, 0, 1, 0x30);
        if (M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) {
            func_0206fcf8(1, 0, 1, 0x30);
            if (M2C_FIELD(&data_0213ad48, u8 *, 6) != 0) {
                func_02090954(0x28);
            }
        }
    }
}
