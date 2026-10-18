/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02076f18(void *, u16, u8);             /* extern */
extern M2C_UNK data_02121eb8;
extern M2C_UNK data_021263e4;
extern M2C_UNK data_021263e6;
extern M2C_UNK data_021263e8;
extern M2C_UNK data_021263ea;
extern M2C_UNK data_021263ec;
extern M2C_UNK data_0213b890;

void func_020d0cbc(u32 arg0, s32 arg1, u8 arg2) {
    u8 var_r2;

    var_r2 = arg2;
    switch (arg0) {
        default:
            break;
        case 0:
            var_r2 = (u8) * ((u16 *) ((s8 *) &data_021263e4 + (M2C_FIELD(&data_0213b890, u8 *, 5) * 0xA)));
            break;
        case 1:
            var_r2 = (u8) * ((u16 *) ((s8 *) &data_021263e6 + (M2C_FIELD(&data_0213b890, u8 *, 5) * 0xA)));
            break;
        case 2:
            var_r2 = (u8) * ((u16 *) ((s8 *) &data_021263e8 + (M2C_FIELD(&data_0213b890, u8 *, 5) * 0xA)));
            break;
        case 3:
            var_r2 = (u8) * ((u16 *) ((s8 *) &data_021263ea + (M2C_FIELD(&data_0213b890, u8 *, 5) * 0xA)));
            break;
        case 4:
            var_r2 = (u8) * ((u16 *) ((s8 *) &data_021263ec + (M2C_FIELD(&data_0213b890, u8 *, 5) * 0xA)));
            break;
    }
    func_02076f18(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x20),
                  *((u16 *) ((s8 *) &data_02121eb8 + (M2C_FIELD(&data_0213b890, u8 *, 5) * 2))), var_r2);
    *M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x20), s32 **, 0x10) = 0;
}
