/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02144cc0;
extern M2C_UNK data_02147cc0;
extern M2C_UNK data_0214838c;

void func_020a1dec(void) {
    M2C_FIELD(&data_02144cc0, void **, 0xDC) =
        (void *) ((M2C_FIELD(M2C_FIELD(&data_02144cc0, void **, 0xDC), u16 *, 4) * 0xC) + (s32) &data_0214838c);
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x800);
    M2C_FIELD(&data_0213ad98, u8 *, 2)     = (u8) M2C_FIELD(&data_0213ad98, u8 *, 4);
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) | 0x45);
    M2C_FIELD(&data_02147cc0, s8 *, 0x542) = 4;
}
