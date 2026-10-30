/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02076e50(M2C_UNK *);                   /* extern */
M2C_UNK func_020a04f0(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020b82fc(u16);                         /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
M2C_UNK func_020f8360(s32, M2C_UNK);                /* extern */
extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213ba90;
extern M2C_UNK data_0213bae8;
extern M2C_UNK func_020cee90;

void func_020cf910(void) {
    if (data_0213ad84 == 0) {
        func_02076e50(&data_0213bae8);
        func_020a04f0(&data_0213bae8, 0x1A3);
        func_020f8360(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 *, 0xC), 7);
        M2C_FIELD(&data_0213b890, s32 *, 0x260)     = 0x141;
        M2C_FIELD(&data_0213b890, s32 *, 0x264)     = -0x20;
        M2C_FIELD(&data_0213b890, s32 *, 0x268)     = 0x30;
        M2C_FIELD(&data_0213ba90, s16 *, 0x6E)      = -0x4000;
        M2C_FIELD(&data_0213ba90, s16 *, 0x6C)      = -0x1800;
        M2C_FIELD(&data_0213b890, M2C_UNK **, 0x44) = &func_020cee90;
        func_0206fcf8(0, 1, 0, 0x100);
        func_020c4798(2);
        func_020b82fc(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x126));
    }
}
