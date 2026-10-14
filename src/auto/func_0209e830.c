/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern u16 data_0213ad84;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213caa0;

void func_0209e830(void) {
    if (data_0213ad84 != 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) = (u8) ((M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) & ~1) | 1);
    if (((u32) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F62) << 0x1E) >> 0x1F) != 0) {
        return;
    }
    if (M2C_FIELD(&data_0213caa0, u8 *, 0x701) == 0) {
        return;
    }
    if (((u32) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) << 0x1A) >> 0x1F) == 1) {
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s8 *, 1) = 1;
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) = (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) & ~0x80);
    } else {
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s8 *, 1) = 3;
        M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) = (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) | 0x80);
    }
    M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s16 *, 2) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) = (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) | 2);
    M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) = (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) & ~8);
    M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), s8 *, 0x2F68) = 1;
}
