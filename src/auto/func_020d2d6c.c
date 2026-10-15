/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020062ac(M2C_UNK, M2C_UNK);
void func_020c0110(M2C_UNK);

extern M2C_UNK data_0213b890;

void func_020d2d6c(void) {
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x24) =
        (s8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEA) + 5);
    func_020062ac(9, (s32) (M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x24));
    func_020062ac(0, (s32) (M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x30));
    func_020062ac(0, (s32) (M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x3C));
    if ((M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEF) == 0) &&
        ((u32) M2C_FIELD(&data_0213b890, u8 *, 0x21) < 2U)) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x48) = 1;
        func_020062ac(0, (s32) (M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x48));
    }
    func_020c0110((s32) (M2C_FIELD(&data_0213b890, void **, 0x4C) + 0xF8));
    func_020c0110((s32) (M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x110));
}
