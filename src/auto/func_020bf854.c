/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b8324(M2C_UNK);                     /* extern */
M2C_UNK func_020bf8b8(M2C_UNK);                     /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020bf854(s32 arg0, s32 arg1) {
    func_020b8324(3);
    func_020bf8b8(0);
    M2C_FIELD(M2C_FIELD(&data_0213b890, s32 *, 0x4C), s8 *, 0x13) =
        (s8) * (s8 *) (arg1 + ((arg0 * 6) + M2C_FIELD(&data_0213b890, s32 *, 0x4C)));
    func_020c4798(2);
    func_0206fcf8(0, 1, 1, 0x100);
}