/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02088648();                                /* extern */
u8 func_02088674();                                 /* extern */
extern M2C_UNK data_02123654;
extern M2C_UNK data_02123660;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bb18;

u8 func_020b6b5c(void) {
    if (func_02088648() != 0) {
        return func_02088674();
    }
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) {
        return (u8) (((u32) * ((M2C_UNK *) ((s8 *) &data_02123660 + (M2C_FIELD(&data_0213ad98, u8 *, 0) * 4))) >>
                      M2C_FIELD(&data_0213ad98, u8 *, 1)) &
                     1);
    }
    return (u8) (((u32) ((s32 *) &data_02123654)[((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1C) >> 0x1E)] >>
                  M2C_FIELD(&data_0213ad98, u8 *, 1)) &
                 1);
}
