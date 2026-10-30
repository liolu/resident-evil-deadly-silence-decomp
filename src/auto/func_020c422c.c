/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020711ac();                            /* extern */
M2C_UNK func_020c46d4(u8, M2C_UNK);                 /* extern */
M2C_UNK func_020d914c();                            /* extern */
extern M2C_UNK data_0212561a;
extern M2C_UNK data_0213ad30;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213ad84;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213ba90;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02147cc0;

void func_020c422c(void) {
    s32 temp_r1;
    s8 var_r3;
    u8 var_r4;

    if (M2C_FIELD(&data_0213b890, u8 *, 2) == 0) {
        var_r4 = M2C_FIELD(&data_0213b890, u8 *, 0x38);
        if (var_r4 == 0) {
            if (M2C_FIELD(&data_0213ad84, u8 *, 9) == 0) {
                if ((M2C_FIELD(&data_02143cc0, u8 *, 0xFDA) == 0) && ((s32) M2C_FIELD(&data_02144bc0, s16 *, 0xD8) >= 0) &&
                    ((M2C_FIELD(&data_0213daa8, u16 *, 0x74) & 0x140) == 0x140) &&
                    !(M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80) && (M2C_FIELD(&data_02143cc0, u8 *, 0xF) == 0)) {
                    if (M2C_FIELD(&data_0213b890, u8 *, 3) != 0) {
                        M2C_FIELD(&data_0213b890, u8 *, 3) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 3) - 1);
                    } else {
                        temp_r1 = M2C_FIELD(&data_0213ad30, u16 *, 2) & 0xC;
                        switch (temp_r1) {          /* irregular */
                            case 8:
                                var_r4 = 0x19;
                                break;
                            case 4:
                                if ((M2C_FIELD(&data_0213ad30, u16 *, 0) & 0x300) == 0x300) {
                                    if (M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) {
                                        var_r4 = 0x16;
                                    } else {
                                        func_020d914c();
                                        func_020711ac();
                                    }
                                } else {
                                    var_r4 = 0x16;
                                }
                                break;
                        }
                    }
                } else {
                    M2C_FIELD(&data_0213b890, u8 *, 3) = 4U;
                }
                if (var_r4 != 0) {
                    func_020c46d4(var_r4, 0);
                    goto block_22;
                }
            }
        } else {
        block_22:
            M2C_FIELD(&data_0213ba90, u16 *, 0x7A) = (u16) M2C_FIELD(&data_0213ad98, u16 *, 0);
            if ((M2C_FIELD(&data_0213b890, u8 *, 0) != 1) && (M2C_FIELD(&data_0213b890, u8 *, 0) != 4)) {
                if (*((u8 *) ((s8 *) &data_0212561a + (var_r4 * 8))) != 0) {
                    func_0206fcf8(1, 1, 1, 0x100);
                }
                func_0206fcf8(0, 1, 1, 0x100);
            }
            M2C_FIELD(&data_0213b890, u8 *, 4) = (u8) M2C_FIELD(&data_02143cc0, u8 *, 0xF4D);
            if (M2C_FIELD(&data_02147cc0, u8 *, 0x540) == 8) {
                var_r3 = 1;
            } else {
                var_r3 = 0;
            }
            M2C_FIELD(&data_0213b890, s8 *, 5) = var_r3;
            M2C_FIELD(&data_0213b890, s8 *, 6) = 0;
            M2C_FIELD(&data_0213b890, s8 *, 8) = 0;
            M2C_FIELD(&data_0213b890, s8 *, 1) = 1;
        }
    }
}
