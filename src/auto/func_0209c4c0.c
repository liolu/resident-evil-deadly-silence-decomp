/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0209f4c8(void *, M2C_UNK, M2C_UNK *, s32, s32); /* extern */
M2C_UNK func_0209f910(M2C_UNK, M2C_UNK, u8, u8, s32, s32); /* extern */
M2C_UNK func_0209f950();                            /* extern */
extern M2C_UNK data_02120a74;
extern M2C_UNK data_02120a75;
extern M2C_UNK data_02120abc;
extern M2C_UNK data_02120ac4;
extern M2C_UNK data_02120acc;
extern M2C_UNK data_0213b2b4;

void func_0209c4c0(void) {
    u8 temp_ip;
    u8 temp_r3;

    if (((u32) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) << 0x1C) >> 0x1F) == 0) {
        func_0209f4c8(M2C_FIELD(&data_0213b2b4, void **, 0xB8) + 0x790, 0, &data_02120abc, 0xE759, 0);
        func_0209f4c8(M2C_FIELD(&data_0213b2b4, void **, 0xB8) + 0x790, 1, &data_02120ac4, 0xE75A, 0);
        func_0209f4c8(M2C_FIELD(&data_0213b2b4, void **, 0xB8) + 0x790, 2, &data_02120acc, 0xE75B, 0);
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) =
            (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) | 8);
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F5B) & 4) {
        if (((u32) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) << 0x19) >> 0x1F) != 0) {
            func_0209f910(0, 0, 0xDCU, 0xA0U, 1, 0);
        } else {
            temp_r3 = M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59);
            func_0209f910(0, 0x14, *((u8 *) ((s8 *) &data_02120a74 + (temp_r3 * 4))),
                          *((u8 *) ((s8 *) &data_02120a75 + (temp_r3 * 4))), 0, 2);
        }
    }
    temp_ip = M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59);
    func_0209f910(0, 0x18, *((u8 *) ((s8 *) &data_02120a74 + (temp_ip * 4))),
                  *((u8 *) ((s8 *) &data_02120a75 + (temp_ip * 4))), 0, 1);
    func_0209f910(0, 0, 0xDCU, 0xA0U, 0, 0);
    func_0209f910(1, 0, 0xD0U, 0x40U, 0xF, 0);
    func_0209f910(1, 0, 0xD0U, 0x78U, 0xF, 0);
    func_0209f950();
}
