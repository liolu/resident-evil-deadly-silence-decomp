/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b3a00(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
s32 func_020d234c();                                /* extern */
M2C_UNK func_020d23f0(s32);                         /* extern */
s32 func_020d2468();                                /* extern */
s32 func_020fef58(s32, s32);                        /* extern */
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213be20;

void func_020d2490(void) {
    s32 temp_ip;
    s32 temp_r2;
    s32 var_r4;

    var_r4 = 0;
    if (M2C_FIELD(&data_0213ae4c, u16 *, 8) == 1) {
        if (func_020d2468() != 1) {
            M2C_FIELD(&data_0213b890, s8 *, 0x21) = 0;
            return;
        }
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0) =
            (s32) (func_020fef58((0x9E - M2C_FIELD(&data_0213ae4c, u16 *, 4)) << 0xC,
                                 (0x56 - M2C_FIELD(&data_0213ae4c, u16 *, 6)) << 0xC)
                   << 0x10);
        temp_ip = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0);
        temp_r2 = temp_ip - M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 4);
        if (temp_r2 < 0) {
            M2C_FIELD(&data_0213b890, s8 *, 0x21) = 0;
            return;
        }
        if ((u32) (temp_r2 + 0x01111000) >= 0x02222000U) {
            var_r4 = temp_r2;
        }
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 4) = temp_ip;
        goto block_9;
    }
    M2C_FIELD(&data_0213b890, s8 *, 0x21) = 0;
block_9:
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xD0) = var_r4;
    func_020d23f0(var_r4);
    if (func_020d234c() != 0) {
        func_020c4798(2);
        func_020b3a00(&data_0213be20, 0x3E);
    }
}
