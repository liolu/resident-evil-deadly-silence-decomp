/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0208db30();                            /* extern */
u8 func_0208dd18();                                 /* extern */
M2C_UNK func_0208dddc(s32);                         /* extern */
M2C_UNK func_0208ea20(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_020afad0();                            /* extern */
extern void *data_02137894;
extern void *data_02137898;

void func_0208d6d4(void) {
    s32 temp_r4;
    u8 temp_r0;
    u8 temp_r1;

    temp_r0 = M2C_FIELD(data_02137898, u8 *, 5);
    temp_r4 = M2C_FIELD(data_02137898, s32 *, 0x30);
    switch (temp_r0) {                              /* irregular */
        case 0:
            func_0208db30();
            M2C_FIELD(data_02137898, u8 *, 8) = func_0208dd18();
            func_020afad0();
            func_0208dddc(temp_r4);
            M2C_FIELD(data_02137898, u8 *, 5) = (u8) (M2C_FIELD(data_02137898, u8 *, 5) + 1);
            return;
        case 1:
            if (M2C_FIELD(data_02137894, u8 *, 3) == 1) {
                func_0208db30();
                func_0208dddc(temp_r4);
                M2C_FIELD(data_02137898, s8 *, 3) = 1;
                M2C_FIELD(data_02137898, u8 *, 5) = (u8) (M2C_FIELD(data_02137898, u8 *, 5) + 1);
                case 2:
                    temp_r1 = M2C_FIELD(data_02137898, u8 *, 8);
                    if ((u32) temp_r1 < 4U) {
                        M2C_FIELD(data_02137898, u8 *, 9) = (u8) ((M2C_FIELD(data_02137898, u8 *, 9) + 1) & 0x1F);
                        func_0208ea20(data_02137898, 0, 2, 0, (s32) (u8) ((((temp_r1 * 4) + 7) * 8) - 8),
                                      (s32) (u8) ((s32) M2C_FIELD(data_02137898, u8 *, 9) >> 4), 0);
                    }
            }
            return;
    }
}
