/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020045d0(M2C_UNK, u8);                     /* extern */
M2C_UNK func_02092bac();                            /* extern */
M2C_UNK func_02092c04(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02092de8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK *func_020af62c(M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_020af6f4(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK *func_020c4798(M2C_UNK);                    /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213e394;

M2C_UNK *func_020b08cc(void) {
    s32 var_r0;

    switch (M2C_FIELD(&data_0213b890, u8 *, 0x21)) { /* irregular */
        case 0:
            if (func_020045d0(0, M2C_FIELD(&data_0213b890, u8 *, 0x1E)) != 0) {
                func_020af6f4(2, 4, 0x60);
                M2C_FIELD(&data_0213b890, u8 *, 0x21) = 1U;
                return &data_0213b890;
            }
            return func_020c4798(4);
        case 1:
            var_r0 = (s32) func_020af62c(0x30, 4);
            if (var_r0 != 0) {
                func_02092c04(0xE721, 0, 0xA, 0x8100);
                func_02092de8(1, 3, 3, 3);
                M2C_FIELD(&data_0213b890, u8 *, 0x21) = 2U;
                return &data_0213b890;
            }
            return (M2C_UNK *) var_r0;
        case 2:
            var_r0 = M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80;
            if (var_r0 == 0) {
                func_02092bac();
                func_020af6f4(2, 4, 0x60);
                if (M2C_FIELD(&data_0213e394, u8 *, 0x16) == 0) {
                    return func_020c4798(4);
                }
                func_020af6f4(2, 4, 0x60);
                var_r0 = (s32) func_020c4798(1);
            /* Duplicate return node #13. Try simplifying control flow for better match */
                return (M2C_UNK *) var_r0;
            }
        /* Duplicate return node #13. Try simplifying control flow for better match */
            return (M2C_UNK *) var_r0;
        default:
            return &data_0213b890;
    }
}
