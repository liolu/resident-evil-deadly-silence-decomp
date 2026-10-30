/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 func_0200e870(u8, u16, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 func_020133a8(M2C_UNK);                         /* extern */
M2C_UNK func_0201367c();                            /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_0209f98c();                                /* extern */
M2C_UNK func_020b7d20(M2C_UNK);                     /* extern */
M2C_UNK func_020b8324(M2C_UNK);                     /* extern */
M2C_UNK func_020d914c();                            /* extern */
extern M2C_UNK data_0213ad3c;
extern u16 data_0213ad84;
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213caa0;

void func_02096608(void) {
    s32 temp_r3;
    s32 var_r5;
    u8 temp_r4;

    var_r5 = -1;
    if (data_0213ad84 == 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) =
            (u8) ((M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) & ~1) | 1);
        temp_r4 = M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59);
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59) =
            func_0200e870(temp_r4, M2C_FIELD(&data_0213ad3c, u16 *, 6), 1, 8, 4, 0, 4, 0);
        if (temp_r4 != M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59)) {
            func_020b8324(0x5D);
        }
        if (M2C_FIELD(&data_0213ae4c, u8 *, 2) != 0) {
            if (func_0209f98c() != 0) {
                var_r5 = 0x7F;
            } else {
                var_r5 = func_020133a8(0);
            }
        } else if (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x20) {
            var_r5 = 0x7F;
        } else if (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x10) {
            var_r5 = (s32) (s8) M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59);
        }
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) =
            (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) | 0x20);
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s8 *, 0x2F5B) = 0x20;
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) =
            (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) & ~0x40);
        switch (var_r5) {                           /* irregular */
            case 0x0:
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59) = (u8) var_r5;
                func_0201367c();
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s32 *, 0) = 2;
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) | 0x20);
                func_0206fcf8(4, 1, 1, 0x80);
                func_020b8324(0x5F);
                return;
            case 0x1:
            case 0x2:
            case 0x3:
            case 0x4:
                temp_r3 = var_r5 - 1;
                if ((s32) M2C_FIELD(&data_0213caa0, u8 *, 0x707) > temp_r3) {
                    M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59) = (u8) var_r5;
                    M2C_FIELD(&data_0213caa0, s8 *, 0x708)                            = (s8) temp_r3;
                    func_0201367c();
                    M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s32 *, 0) = 2;
                    func_0206fcf8(4, 1, 1, 0x80);
                    func_020b8324(0x5F);
                    return;
                }
                func_020b8324(0x60);
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) & ~0x20);
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s8 *, 0x2F5B) = 0;
                return;
            case 0x7F:
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) | 0x40);
                func_0201367c();
                func_020d914c();
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s32 *, 0) = 3;
                func_0206fcf8(4, 1, 1, 0x80);
                func_020b8324(0x5E);
                func_020b7d20(0x5A);
                return;
            default:
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) & ~0x20);
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s8 *, 0x2F5B) = 0;
                break;
        }
    }
}
