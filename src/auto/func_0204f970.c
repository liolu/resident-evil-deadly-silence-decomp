#include "m2c.h"

extern M2C_UNK data_0212cf78;

void func_0204f970(void *arg0) {
    s16 temp_r1;

    if ((u32) M2C_FIELD(arg0, u8 *, 0xA2) > 2U) {
        temp_r1 = M2C_FIELD(arg0, s16 *, 0xA8);
        if ((s32) temp_r1 <= 0xA) {
            M2C_FIELD(arg0, s16 *, 0x184) = (s16) * ((s16 *) ((s8 *) &data_0212cf78 + ((0xA - temp_r1) * 2)));
        }
        M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) + 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x182) == 0) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x91) = 0;
    if (M2C_FIELD(arg0, u8 *, 0xA) != 0x80) {
        M2C_FIELD(arg0, u8 *, 0xA) = 2U;
    }
    M2C_FIELD(arg0, s16 *, 0x44)  = (s16) M2C_FIELD(arg0, s16 *, 0x18E);
    M2C_FIELD(arg0, s16 *, 0x190) = 0;
    M2C_FIELD(arg0, s16 *, 0x180) = 0;
    M2C_FIELD(arg0, s16 *, 0x184) = 0;
}
