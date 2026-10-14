/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200ef34();                            /* extern */
M2C_UNK func_02053bec();                            /* extern */
M2C_UNK func_02053c54();                         /* extern */
M2C_UNK func_020769b0();                         /* extern */
M2C_UNK func_02076bb4();                         /* extern */
M2C_UNK func_020b3a00();          /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213be00;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;

void func_020c8c24(void) {
    func_02076bb4(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x108);
    func_020769b0(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x109);
    func_02076bb4(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x114);
    func_020769b0(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x115);
    func_02053c54(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x18));
    func_02053c54(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x1C));
    func_02053bec();
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) | 7);
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) | 0x100);
    func_0200ef34();
    M2C_FIELD(&data_0213ad98, u8 *, 2) = (u8) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x104);
    func_020b3a00(&data_0213be00, 0x20);
    M2C_FIELD(&data_02143cc0, s32 *, 0xF78) = (s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xC);
    M2C_FIELD(&data_0213b890, s32 *, 0x78) = 0;
}
