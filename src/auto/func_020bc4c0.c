/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020555b4(void *);                      /* extern */
M2C_UNK func_02072dc8(void *, s32);                 /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_02091514(void *, s32, s32);            /* extern */
M2C_UNK func_020915f0(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_02091624(void *, s32, s32);            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020bb594(M2C_UNK);                     /* extern */
M2C_UNK func_020bb6ec(s32);                         /* extern */
M2C_UNK func_020bb780(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_021248b0;
extern u16 data_0213ad98;
extern M2C_UNK data_0213be00;
extern void *data_027e000c;

void func_020bc4c0(void) {
    void *temp_ip;

    func_020bb594(0x23);
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 0;
    if (func_020b39e4(&data_0213be00, 0x37) != 0) {
        func_020bb6ec(0x8063);
        func_02072dc8(M2C_FIELD(data_027e000c, void **, 0), M2C_FIELD(data_027e000c, s32 *, 0x188));
        temp_ip = M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0), void **, 0x10);
        M2C_FIELD(temp_ip, s32 *, 0) = (s32) (M2C_FIELD(M2C_FIELD(temp_ip, void **, 8), u16 *, 4) << 0xC);
        func_02091624(data_027e000c + 0x54, 0x3FE66666, 0x40400000);
        func_020555b4(data_027e000c);
        func_020915f0(data_027e000c + 0x54, 0, 0);
        func_02091514(data_027e000c + 0x54, 0x7DC, 0x85C);
        func_02075738(0, 0x400);
    } else {
        func_020bb780(0, 0x400);
    }
    M2C_FIELD(data_027e000c, M2C_UNK **, 0xC) = &data_021248b0;
    if (data_0213ad98 == 0x1104) {
        M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) | 2);
    }
}
