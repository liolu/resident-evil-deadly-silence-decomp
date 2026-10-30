/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02005c14();            /* extern */
M2C_UNK func_02005c34();                            /* extern */
M2C_UNK func_0206fcf8(); /* extern */
M2C_UNK func_020b8c4c();                    /* extern */
s32 func_020b8ca8();                         /* extern */
s32 func_020b8d98();                             /* extern */
extern M2C_UNK data_0213b890;

void func_020b8dd4(void) {
    s32 temp_r1;
    s32 temp_r2;
    s32 temp_r2_2;
    s32 var_r4;

    M2C_FIELD(&data_0213b890, u16 *, 0x26) = 0x150U;
    func_020b8c4c((s16) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0),
                  (s16) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 8));
    var_r4 = func_020b8ca8(1);
    if (var_r4 != 0) {
        var_r4              = 0;
        *(s32 *) 0x04001000 = (*(s32 *) 0x04001000 & ~0x1F00) | 0xA00;
        temp_r1             = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x18);
        if (temp_r1 < 0x10000) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x18) =
                (s32) (temp_r1 + M2C_FIELD(&data_0213b890, u16 *, 0x26));
        }
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x18) > 0) {
            *(M2C_UNK *) 0x04001000 = (s32) ((*(M2C_UNK *) 0x04001000 & ~0x1F00) | 0xE00);
            temp_r2                 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x10);
            if (temp_r2 < 0) {
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x10) =
                    (s32) (temp_r2 + M2C_FIELD(&data_0213b890, u16 *, 0x26));
                if ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x10) > 0) {
                    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x10) = 0;
                }
            } else {
                var_r4 = 1;
            }
            *(s32 *) 0x04000000 = (*(s32 *) 0x04000000 & ~0x1F00) | 0xA00;
            temp_r2_2           = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x20);
            if (temp_r2_2 < 0) {
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x20) =
                    (s32) (temp_r2_2 + M2C_FIELD(&data_0213b890, u16 *, 0x26));
                if ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x20) > 0) {
                    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x20) = 0;
                }
            }
        }
    }
    if ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 8) > 0xE000) {
        func_020b8ca8(0);
    }
    func_02005c34();
    if (func_020b8d98(var_r4) != 0) {
        func_02005c14(0, -0x18);
        func_0206fcf8(4, 2, 1, 0x100);
        M2C_FIELD(&data_0213b890, s8 *, 0x20) = 2;
    }
}
