/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02090250(u8, M2C_UNK);                 /* extern */
M2C_UNK func_02090288(u8, s32, s32);                /* extern */
extern M2C_UNK data_0211f8ec;
extern M2C_UNK data_0211f8f0;

void func_0208cee4(void *arg0) {
    s32 temp_r3;

    M2C_FIELD(arg0, s8 *, 0x4BC) = 0;
    M2C_FIELD(arg0, s8 *, 0x286) = 0;
    func_02090250(M2C_FIELD(arg0, u8 *, 0x2A6), 4);
    temp_r3 = M2C_FIELD(arg0, u8 *, 0x4C4) * 0x28;
    func_02090288(M2C_FIELD(arg0, u8 *, 0x2A6), *((M2C_UNK *) ((s8 *) &data_0211f8ec + temp_r3)),
                  *((M2C_UNK *) ((s8 *) &data_0211f8f0 + temp_r3)));
    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, s16 *, 0x28E) = 0;
        M2C_FIELD(arg0, s16 *, 0x28C) = (s16) M2C_FIELD(arg0, s16 *, 0x28E);
        M2C_FIELD(arg0, s16 *, 0x292) = 0;
        M2C_FIELD(arg0, s16 *, 0x290) = (s16) M2C_FIELD(arg0, s16 *, 0x292);
        M2C_FIELD(arg0, s16 *, 0x29C) = 0;
    }
}
