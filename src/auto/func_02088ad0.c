/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0211f7d0;
extern M2C_UNK data_0211f7d1;
extern M2C_UNK data_0211f7d2;
extern M2C_UNK data_0213daa8;

void func_02088ad0(u32 arg0, s32 arg1) {
    if (arg0 >= 0x23U) {
        M2C_FIELD(&data_0213daa8, u8 *, 0x85A) = 1U;
        return;
    }
    switch (arg1) {                                 /* irregular */
        case 11:
            M2C_FIELD(&data_0213daa8, u8 *, 0x85A) = (u8) * ((u8 *) ((s8 *) &data_0211f7d0 + (arg0 * 8)));
            return;
        case 12:
            M2C_FIELD(&data_0213daa8, u8 *, 0x85A) = (u8) * ((u8 *) ((s8 *) &data_0211f7d1 + (arg0 * 8)));
            return;
        case 14:
            M2C_FIELD(&data_0213daa8, u8 *, 0x85A) = (u8) * ((u8 *) ((s8 *) &data_0211f7d2 + (arg0 * 8)));
            return;
        default:
            M2C_FIELD(&data_0213daa8, u8 *, 0x85A) = 1U;
            return;
    }
}
