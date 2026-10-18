/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0206fe7c(M2C_UNK *, M2C_UNK, u8, M2C_UNK, s32); /* extern */
extern M2C_UNK data_0211e7ac;
extern M2C_UNK data_0213ade4;
extern M2C_UNK data_0213b2b4;

void func_02078de0(s32 arg0) {
    s32 temp_ip;

    temp_ip = arg0 & 0xF;
    func_0206fe7c(&data_0213ade4, 3, *((u8 *) ((s8 *) &data_0211e7ac + (temp_ip * 2))), 1,
                  M2C_FIELD(&data_0213b2b4, s32 *, 0xC8) + 0xF000);
    func_0206fe7c(&data_0213ade4, 1, M2C_FIELD(((M2C_UNK *) ((s8 *) &data_0211e7ac + (temp_ip * 2))), u8 *, 1), 1,
                  M2C_FIELD(&data_0213b2b4, s32 *, 0xC8) + 0x8000);
}
