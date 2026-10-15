/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020035e4(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020979dc(M2C_UNK);                     /* extern */
M2C_UNK func_020980c0(void *, void *, u8);          /* extern */
M2C_UNK func_0209814c(void *, u8, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02098248();                            /* extern */
M2C_UNK func_020b8324(M2C_UNK);                     /* extern */
M2C_UNK func_02106088(M2C_UNK *, void *, M2C_UNK);  /* extern */
M2C_UNK func_021061d8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_02120694;
extern M2C_UNK data_02120770;
extern M2C_UNK data_02120910;
extern void *data_02137ed8;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213f2e8;
extern M2C_UNK data_02143cc0;
extern M2C_UNK func_020985cc;

void func_020974a8(void) {
    void *temp_r4;

    func_020979dc(1);
    func_021061d8(&data_0213f2e8, 0, 0x100);
    func_020035e4(2, &data_0213f2e8, 0, 0x100);
    temp_r4                               = data_02137ed8 + 4;
    M2C_FIELD(data_02137ed8, u8 *, 0x264) = (u8) M2C_FIELD(data_02137ed8, u8 *, 0x24B2);
    M2C_FIELD(&data_02143cc0, s8 *, 0xE)  = 1;
    func_0209814c(temp_r4, M2C_FIELD(data_02137ed8, u8 *, 0x24B2), 0, 0);
    func_020980c0(temp_r4, data_02137ed8 + 0x84, M2C_FIELD(data_02137ed8, u8 *, 0x24B2));
    M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 0;
    func_02106088(&data_02120910, temp_r4 + 8, 0x12);
    M2C_FIELD(temp_r4, s32 *, 0x1C) = 0x3800;
    func_020038b8(&data_02120694);
    M2C_FIELD(data_02137ed8, M2C_UNK **, 0x2454) = &data_02120770;
    M2C_FIELD(data_02137ed8, u16 *, 0x24B4)      = (u16) ((M2C_FIELD(data_02137ed8, u16 *, 0x24B4) & ~0x1F) | 0xE);
    M2C_FIELD(data_02137ed8, u16 *, 0x24B4)      = (u16) (M2C_FIELD(data_02137ed8, u16 *, 0x24B4) & ~0x3E0);
    M2C_FIELD(data_02137ed8, u16 *, 0x24B4)      = (u16) (M2C_FIELD(data_02137ed8, u16 *, 0x24B4) & ~0x7C00);
    func_02098248();
    *(s32 *) 0x04000000                         = (*(s32 *) 0x04000000 & ~0x1F00) | 0xD00;
    M2C_FIELD(&data_0213b890, M2C_UNK **, 0x44) = &func_020985cc;
    M2C_FIELD(data_02137ed8, u8 *, 0x24AF)      = (u8) (M2C_FIELD(data_02137ed8, u8 *, 0x24AF) & ~4);
    func_0206fcf8(0, 2, 0, 0x100);
    M2C_FIELD(&data_0213b890, s8 *, 0x24) = 0x2D;
    M2C_FIELD(data_02137ed8, s8 *, 0)     = 1;
    func_020b8324(0x61);
}
