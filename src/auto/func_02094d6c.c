/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02094e28(u8, void *);                      /* extern */
M2C_UNK func_02094f90(u8, s16);                     /* extern */
s32 func_0211851c(s32, M2C_UNK);                    /* extern */
extern M2C_UNK data_0212038c;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;

void func_02094d6c(void *arg0) {
    u16 temp_r0;

    if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
        temp_r0 = M2C_FIELD(arg0, u16 *, 0x172);
        if (((u32) temp_r0 >= 0x80U) && (temp_r0 != 0xFF) && (func_02094e28((u8) temp_r0, arg0 + 0x94) == 0)) {
            if ((((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1E) >> 0x1F) == 1) &&
                (((u8 *) &data_0212038c)[M2C_FIELD(arg0, u8 *, 9)] != 0)) {
                M2C_FIELD(arg0, s16 *, 0x94) =
                    (s16) (M2C_FIELD(arg0, s16 *, 0x94) +
                           func_0211851c(M2C_FIELD(arg0, s16 *, 0x94) * (M2C_FIELD(&data_0213bb18, u8 *, 0x202) - 1), 2));
            }
            func_02094f90((u8) M2C_FIELD(arg0, u16 *, 0x172), M2C_FIELD(arg0, s16 *, 0x94));
        }
    }
}
