/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02076fc4();                              /* extern */
void *func_020771d4(s32, M2C_UNK);                  /* extern */
void *func_020a0100(u8);                            /* extern */
M2C_UNK func_020f4488(void *, s32);                 /* extern */
M2C_UNK func_020f4658(void *, void *);              /* extern */
M2C_UNK func_020f46c0(s32, s32, void *, M2C_UNK);   /* extern */
s32 func_020f82a8(M2C_UNK *, s32, void *);          /* extern */
M2C_UNK func_020f83f0(void *, M2C_UNK);             /* extern */
M2C_UNK func_020f8678(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_020f86e8(void *, M2C_UNK, M2C_UNK);    /* extern */
void *func_020f8798(s32);                           /* extern */
s32 func_020f8b40(s32, M2C_UNK);                    /* extern */
extern M2C_UNK data_0213b38c;
extern s32 data_021402e8;

void *func_02077000(void *arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_r0_3;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r4;

    temp_r4                          = func_02076fc4();
    temp_r0                          = func_020f8798(M2C_FIELD(arg0, s32 *, 4));
    M2C_FIELD(temp_r4, void **, 0xC) = (void *) (temp_r0 + M2C_FIELD((temp_r0 + M2C_FIELD(temp_r0, u16 *, 0xE)), s32 *, 0xC));
    func_020f4658(temp_r4 + 0x20, M2C_FIELD(temp_r4, void **, 0xC));
    func_020f83f0(M2C_FIELD(temp_r4, void **, 0xC), 0);
    func_020f86e8(M2C_FIELD(temp_r4, void **, 0xC), 0, 0x400);
    func_020f8678(M2C_FIELD(temp_r4, void **, 0xC), 0, 0xF);
    func_020f86e8(M2C_FIELD(temp_r4, void **, 0xC), 1, 0x40);
    func_020f86e8(M2C_FIELD(temp_r4, void **, 0xC), 1, 0x80);
    func_020f86e8(M2C_FIELD(temp_r4, void **, 0xC), 1, 0x200);
    if (arg1 == 0) {
        M2C_FIELD(temp_r4, void **, 4) = arg0;
        M2C_FIELD(temp_r4, void **, 8) = NULL;
        return temp_r4;
    }
    temp_r0_2                       = func_020771d4(arg1, arg2);
    M2C_FIELD(temp_r4, void **, 4)  = arg0;
    M2C_FIELD(temp_r4, void **, 8)  = temp_r0_2;
    temp_r0_3                       = func_020f8b40(M2C_FIELD(temp_r0_2, s32 *, 4), 0);
    M2C_FIELD(temp_r4, s32 *, 0x10) = func_020f82a8(&data_0213b38c, temp_r0_3, M2C_FIELD(temp_r4, void **, 0xC));
    func_020f46c0(M2C_FIELD(temp_r4, s32 *, 0x10), temp_r0_3, M2C_FIELD(temp_r4, void **, 0xC), 0);
    func_020f4488(temp_r4 + 0x20, M2C_FIELD(temp_r4, s32 *, 0x10));
    M2C_FIELD(temp_r4, void **, 0x14) = func_020a0100(M2C_FIELD(M2C_FIELD(temp_r4, void **, 0xC), u8 *, 0x17));
    M2C_FIELD(temp_r4, s32 *, 0x54)   = (s32) ((M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x14), u8 *, 1) * 0x58) + data_021402e8);
    M2C_FIELD(temp_r4, s32 *, 0x1C)   = 0;
    return temp_r4;
}
