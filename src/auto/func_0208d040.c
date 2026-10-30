/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0208b3b0(void *);                      /* extern */
M2C_UNK func_0208bed8(void *, M2C_UNK);             /* extern */
M2C_UNK func_02090250(u8, M2C_UNK);                 /* extern */
M2C_UNK func_02090288(u8, s32, s32);                /* extern */
extern M2C_UNK data_0211f8ec;
extern M2C_UNK data_0211f8f0;

void func_0208d040(void *arg0) {
    s32 temp_r3;
    u8 temp_r0;

    M2C_FIELD(arg0, s8 *, 0x4BC) = 0;
    M2C_FIELD(arg0, s8 *, 0x286) = 0;
    func_02090250(M2C_FIELD(arg0, u8 *, 0x2A6), 4);
    temp_r3 = M2C_FIELD(arg0, u8 *, 0x4C4) * 0x28;
    func_02090288(M2C_FIELD(arg0, u8 *, 0x2A6), *((M2C_UNK *) ((s8 *) &data_0211f8ec + temp_r3)),
                  *((M2C_UNK *) ((s8 *) &data_0211f8f0 + temp_r3)));
    temp_r0 = M2C_FIELD(arg0, u8 *, 0x92);
    switch (temp_r0) {                              /* irregular */
        case 1:
            if (M2C_FIELD(arg0, u8 *, 0x2A5) != 0) {
                func_0208b3b0(arg0);
            }
        /* fallthrough */
        case 0:
            func_0208bed8(arg0, 0);
            return;
        case 2:
            if (M2C_FIELD(arg0, u8 *, 0x2A5) != 0) {
                func_0208b3b0(arg0);
            }
            return;
    }
}
