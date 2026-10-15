/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c70e0(void) {
    s16 temp_r1;
    s8 var_r0;

    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) - 1);
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10);
    if (temp_r1 == 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0;
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x4B) == 1) {
            M2C_FIELD(&data_0213b890, s8 *, 0x21) = 4;
            M2C_FIELD(&data_0213b890, s8 *, 0x22) = 0;
            return;
        }
        M2C_FIELD(&data_0213b890, u8 *, 0x23)                            = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x23) + 1);
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0x1E;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) = 0;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x4A)  = 0;
        return;
    }
    if (!(temp_r1 & 0x10)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x4A) = var_r0;
}
