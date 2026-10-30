/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd214(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0201ea80(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_02144c34;

void func_0201f7c8(void *arg0) {
    if ((u32) M2C_FIELD(arg0, u8 *, 0xA2) > 7U) {
        func_0201ea80(arg0, 0x20, 0x28);
    }
    func_01ffd214(&data_02144c34, 0x40);
    if (func_0209109c(0, 0x400, 5) != 0) {
        M2C_FIELD(arg0, s8 *, 0x90) = 1;
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0xA)  = 4;
        M2C_FIELD(arg0, s8 *, 0x96) = 0;
    }
}
