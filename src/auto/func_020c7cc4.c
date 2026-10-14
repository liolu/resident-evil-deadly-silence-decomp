/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020c5d34(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020c5da8(M2C_UNK);

extern M2C_UNK data_0213b890;

void func_020c7cc4(void) {
    M2C_FIELD(&data_0213b890, u8 *, 0x22) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x22) + 1);
    M2C_FIELD(&data_0213b890, s8 *, 0x23) = 0;
    func_020c5d34(0, -0x90, -0x68, 0);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x54) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x5E) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xB2) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xA8) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0xBC) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xC4) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xC5) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0xC6) = 7;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0xC8) = 2;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xD3) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xD6) = 0;
    func_020c5da8(0);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x4A) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 4) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 8) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x102) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x100) = 0x85;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x18), s8 *, 0xA) = 0x47;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x1C), s8 *, 0xA) = 0x47;
}
