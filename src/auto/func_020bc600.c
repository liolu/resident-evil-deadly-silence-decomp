/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020555b4(void *);                      /* extern */
M2C_UNK func_02072dc8(void *, s32);                 /* extern */
M2C_UNK func_020915f0(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_02091624(void *, s32, s32);            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020bb594(M2C_UNK);                     /* extern */
M2C_UNK func_020bb6ec(M2C_UNK);                     /* extern */
M2C_UNK func_020bb780(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_021248bc;
extern M2C_UNK data_0213bde0;
extern M2C_UNK data_0213be00;
extern void *data_027e000c;

void func_020bc600(void) {
    if (func_020b39e4(&data_0213be00, 0x70) != 0) {
        func_020bb594(0x2F);
    } else {
        func_020bb594(0x22);
    }
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 0;
    if ((func_020b39e4(&data_0213bde0, 0xC0) != 0) && (M2C_FIELD(data_027e000c, u8 *, 9) == 0x2C)) {
        M2C_FIELD(data_027e000c, s8 *, 0x168) = 1;
        M2C_FIELD(data_027e000c, s8 *, 7) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
        func_020bb6ec(0x58);
        func_02072dc8(M2C_FIELD(data_027e000c, void **, 0), M2C_FIELD(data_027e000c, s32 *, 0x188));
        M2C_FIELD(data_027e000c, u8 *, 0xA2) = 0x3DU;
        *M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0), s32 **, 0x10) = M2C_FIELD(data_027e000c, u8 *, 0xA2) << 0xC;
        func_02091624(data_027e000c + 0x54, 0x3FE66666, 0x40400000);
        func_020555b4(data_027e000c);
        func_020915f0(data_027e000c + 0x54, 0, 0);
    }
    func_020bb780(0, 0x1000);
    M2C_FIELD(data_027e000c, M2C_UNK **, 0xC) = &data_021248bc;
}
