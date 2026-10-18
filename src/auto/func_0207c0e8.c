/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0208509c(void *);                      /* extern */
M2C_UNK func_02090a10(s32, M2C_UNK, s32);           /* extern */
M2C_UNK func_02090fc4(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_020a04b8(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_020a0518(void *, s32, M2C_UNK);        /* extern */
extern M2C_UNK data_0211f298;

void func_0207c0e8(void *arg0) {
    s32 var_r2;
    void *temp_lr;
    void *temp_r1;

    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 8)   = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0xB) = 1;
    temp_lr                                           = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_lr, u16 *, 0x42) = (u16) * ((u16 *) ((s8 *) &data_0211f298 + (M2C_FIELD(temp_lr, u8 *, 0xA) * 2)));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s16 *, 0x44) = 0x800;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s16 *, 0x46) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x98)  = 0;
    func_020a0518(M2C_FIELD(arg0, void **, 0), 0x1BE, 0x28);
    func_020a04b8(M2C_FIELD(arg0, void **, 0), 0x28, 0);
    func_02090fc4(0, 0x1000, 0);
    func_0208509c(arg0);
    M2C_FIELD(arg0, s8 *, 0x17) = 0x1F;
    temp_r1                     = M2C_FIELD(arg0, void **, 0);
    if (M2C_FIELD(temp_r1, u8 *, 0xA) != 0) {
        var_r2 = 0x7FF;
    } else {
        var_r2 = 0x7F7;
    }
    func_02090a10(M2C_FIELD(temp_r1, s32 *, 0), 0xB, var_r2);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x90) = 1;
}
