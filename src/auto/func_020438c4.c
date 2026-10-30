/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020478e0();                            /* extern */
M2C_UNK func_02047eb0(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02047ff0(void *, u8, M2C_UNK);         /* extern */
s32 func_02088648();                                /* extern */
M2C_UNK func_02090450(u8);                          /* extern */
M2C_UNK func_020b3864(void *);                      /* extern */
M2C_UNK func_020b842c(M2C_UNK, M2C_UNK);            /* extern */
extern u8 data_02137364;
extern void *data_02137370;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213daa8;
extern void *data_027e000c;

void func_020438c4(void) {
    func_020b3864(data_027e000c);
    M2C_FIELD(data_027e000c, u8 *, 0xA)   = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) | 0x40);
    M2C_FIELD(data_027e000c, s8 *, 0xA2)  = 0;
    M2C_FIELD(data_027e000c, s8 *, 0xA3)  = 0;
    M2C_FIELD(data_027e000c, u8 *, 0xA1)  = 0xAU;
    M2C_FIELD(data_027e000c, s8 *, 0x98)  = 0;
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0;
    M2C_FIELD(data_02137370, u8 *, 0xD)   = (u8) (M2C_FIELD(data_02137370, u8 *, 0xD) & ~2);
    M2C_FIELD(data_027e000c, s8 *, 0xBC)  = 0;
    func_02090450(data_02137364);
    data_02137364                         = 0;
    M2C_FIELD(data_027e000c, s16 *, 0x94) = 1;
    func_020478e0();
    func_02047ff0(data_027e000c, M2C_FIELD(data_027e000c, u8 *, 0xA1), 0);
    func_02047eb0(data_027e000c, 0, 0x1000, 5);
    M2C_FIELD(data_027e000c, s8 *, 0x90) = 8;
    M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x92) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x93) = 1;
    if ((M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) && (func_02088648() == 0)) {
        func_020b842c(0, 0x11);
        M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & 0xFFFFFEFE);
    }
}
