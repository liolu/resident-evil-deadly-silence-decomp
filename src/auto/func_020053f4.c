/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020ed884(s32);                         /* extern */
M2C_UNK func_020ed8d8(s32, M2C_UNK);                /* extern */
M2C_UNK func_020ed8e4(s32, u16, u16);               /* extern */
extern void *data_02137264;

void func_020053f4(s8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(data_02137264, s32 *, 0xC) = 1;
    func_020ed8e4(M2C_FIELD(data_02137264, s32 *, 0x53C), M2C_FIELD(data_02137264, u16 *, 0x16),
                  M2C_FIELD(data_02137264, u16 *, 0x18));
    func_020ed8d8(M2C_FIELD(data_02137264, s32 *, 0x53C), arg1);
    if (*arg0 != 0) {
        func_020ed884(M2C_FIELD(data_02137264, s32 *, 0x53C));
        M2C_FIELD(data_02137264, s32 *, 8) = 0;
        M2C_FIELD(data_02137264, s8 *, 0)  = 1;
    }
}
