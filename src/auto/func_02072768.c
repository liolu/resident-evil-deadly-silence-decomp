/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213af7c;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213daa8;

void func_02072768(void) {
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0xD1FD003F);
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & ~0x100);
    M2C_FIELD(&data_0213ad98, s8 *, 5)     = 0;
    M2C_FIELD(&data_0213af7c, s16 *, 0x28) = 0;
    M2C_FIELD(&data_0213af7c, s8 *, 0x27)  = 0;
    M2C_FIELD(&data_0213af7c, s8 *, 0x26)  = 0;
    func_0206fcf8(0, 0, 1, 0x80);
}
