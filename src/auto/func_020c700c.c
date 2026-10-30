/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c4da4(void *, M2C_UNK *);           /* extern */
M2C_UNK func_020c4dd8(void *);                      /* extern */
M2C_UNK func_020c83d8(void *, void *);              /* extern */
extern M2C_UNK data_0212585c;
extern M2C_UNK data_0213b890;

void func_020c700c(void) {
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) - 1);
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) == 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0x1E;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) + 1);
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) == 3) {
            M2C_FIELD(&data_0213b890, s8 *, 0x21)                            = 3;
            M2C_FIELD(&data_0213b890, s8 *, 0x22)                            = 0;
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0x1E;
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) = 0;
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x49)  = 0x32;
        }
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) != 0) {
        func_020c4dd8(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120);
        func_020c4da4(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, &data_0212585c);
        func_020c83d8(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x108);
    }
}
