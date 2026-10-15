/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020038b8(M2C_UNK);
void func_020c9ccc(M2C_UNK);

extern M2C_UNK data_02125c0c;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_027e01ac;

void func_020ca1c8(void) {
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 2) == 1) {
        M2C_FIELD(&data_027e01ac, s16 *, 0x20) = -0xBC;
    } else {
        M2C_FIELD(&data_027e01ac, s16 *, 0x20) = 0xBA;
    }
    func_020c9ccc(1);
    M2C_FIELD(&data_0213b890, s8 *, 0x25) = 0x10;
    func_020038b8(*((M2C_UNK *) ((s8 *) &data_02125c0c + (M2C_FIELD(&data_0213b890, u8 *, 0x24) * 8))));
}
