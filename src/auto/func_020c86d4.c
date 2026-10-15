/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0200f208(void);
void func_0200f40c(void);
void func_020f4c6c(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_0214bcc0;

void func_020c86d4(void) {
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x104) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 2);
    M2C_FIELD(M2C_FIELD(&data_0214bcc0, void **, 0x7AC), u16 *, 6)   = 0x708U;
    M2C_FIELD(M2C_FIELD(&data_0214bcc0, void **, 0x7AC), u16 *, 8)   = 0x708U;
    M2C_FIELD(M2C_FIELD(&data_0214bcc0, void **, 0x7AC), u16 *, 0xA) = 0x708U;
    func_020f4c6c(0,
                  (s32) (u16) (((s32) M2C_FIELD(M2C_FIELD(&data_0214bcc0, void **, 0x7AC), u16 *, 6) >> 7) |
                               (((s32) M2C_FIELD(M2C_FIELD(&data_0214bcc0, void **, 0x7AC), u16 *, 8) >> 7) << 5) |
                               (((s32) M2C_FIELD(M2C_FIELD(&data_0214bcc0, void **, 0x7AC), u16 *, 0xA) >> 7) << 0xA)),
                  0);
    M2C_FIELD(&data_0213ad98, s8 *, 0) = 4;
    M2C_FIELD(&data_0213ad98, s8 *, 1) = 6;
    M2C_FIELD(&data_0213ad98, u8 *, 2) = 4U;
    func_0200f208();
    func_0200f40c();
    M2C_FIELD(&data_02143cc0, s32 *, 0x28) = 0x382000;
    M2C_FIELD(&data_02143cc0, s32 *, 0x2C) = 0xC7000;
    M2C_FIELD(&data_02143cc0, s32 *, 0x30) = 0xFFE22000;
    M2C_FIELD(&data_02143cc0, s32 *, 0x34) = 0x3FC000;
    M2C_FIELD(&data_02143cc0, s32 *, 0x38) = 0x5E000;
    M2C_FIELD(&data_02143cc0, s32 *, 0x3C) = 0xFFE22000;
}
