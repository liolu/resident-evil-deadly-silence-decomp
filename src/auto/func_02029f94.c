/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd214(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */
M2C_UNK func_02029f30(void *);                      /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_02144c34;

void func_02029f94(void *arg0) {
    func_020559cc(arg0, 0);
    func_01ffd214(&data_02144c34, 0x80);
    func_02029f30(arg0);
    M2C_FIELD(arg0, s16 *, 0xA6) = 0xC8;
    func_01ffd504(0);
    M2C_FIELD(arg0, s16 *, 0x186) = (s16) (M2C_FIELD(arg0, s16 *, 0x186) + 1);
    M2C_FIELD(arg0, s32 *, 0x34)  = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + M2C_FIELD(arg0, s16 *, 0x186));
    if ((s32) M2C_FIELD(arg0, s32 *, 0x34) > -2550) {
        M2C_FIELD(arg0, s8 *, 0x90) = 1;
        M2C_FIELD(arg0, s8 *, 0x91) = 1;
        M2C_FIELD(arg0, s8 *, 0x92) = 2;
        M2C_FIELD(arg0, s8 *, 0x93) = 0;
    }
}
