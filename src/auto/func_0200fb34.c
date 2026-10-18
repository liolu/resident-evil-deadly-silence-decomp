/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020f3978(s32, s32, s32, u16, s32);     /* extern */
M2C_UNK func_020f3b7c(s32, s32, u16, M2C_UNK);      /* extern */
extern M2C_UNK data_0211b958;
extern M2C_UNK data_0213b2b4;

void func_0200fb34(s32 arg0) {
    s32 temp_r1;
    void *temp_r4;

    temp_r1 = arg0 * 0xC;
    temp_r4 = (M2C_UNK *) ((s8 *) &data_0211b958 + temp_r1);
    func_020f3978(*((M2C_UNK *) ((s8 *) &data_0211b958 + temp_r1)), M2C_FIELD(temp_r4, s32 *, 4),
                  M2C_FIELD(&data_0213b2b4, s32 *, 0xC0), M2C_FIELD(&data_0213b2b4, u16 *, 0xBE), 1);
    func_020f3b7c(M2C_FIELD(temp_r4, s32 *, 8), M2C_FIELD(&data_0213b2b4, s32 *, 0xC4), M2C_FIELD(&data_0213b2b4, u16 *, 0xBE),
                  1);
}
