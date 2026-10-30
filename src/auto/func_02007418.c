/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02103a58(void *);                      /* extern */
extern void *data_02137298;

void func_02007418(s32 arg0) {
    if (arg0 == -1) {
        M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) | 2);
        M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) | 4);
        return;
    }
    func_02103a58(data_02137298 + 0x1CEC);
}
