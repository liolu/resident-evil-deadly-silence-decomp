/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02070ecc(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213ad50;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213bf46;
extern M2C_UNK data_0213bfcc;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02144cc0;

void func_020711e0(void) {
    M2C_FIELD(&data_0213bdcc, s16 *, 8)   = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF74);
    M2C_FIELD(&data_0213bdcc, s16 *, 0xA) = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF7C);
    M2C_FIELD(&data_0213bdcc, s16 *, 0xC) = (s16) M2C_FIELD(&data_02144bc0, s16 *, 0x88);
    M2C_FIELD(&data_0213bdcc, u8 *, 4)    = (u8) M2C_FIELD(&data_02144cc0, u8 *, 4);
    M2C_FIELD(&data_0213bdcc, u8 *, 3)    = (u8) M2C_FIELD(&data_02143cc0, u8 *, 0xF4D);
    func_02070ecc((s32) &data_0213ad50, (s32) &data_0213bf46);
    M2C_FIELD(&data_0213bdcc, u8 *, 0x25E) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 0);
    M2C_FIELD(&data_0213bdcc, u8 *, 0x25F) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 1);
    M2C_FIELD(&data_0213bdcc, u8 *, 0x260) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 2);
    M2C_FIELD(&data_0213bdcc, u8 *, 0x261) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 3);
    M2C_FIELD(&data_0213bdcc, u8 *, 0x262) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 9);
    M2C_FIELD(&data_0213bdcc, u8 *, 0x263) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 0xC);
    M2C_FIELD(&data_0213bdcc, u8 *, 0x264) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 0xD);
    M2C_FIELD(&data_0213bdcc, u8 *, 0x265) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 0xE);
    M2C_FIELD(&data_0213bdcc, u8 *, 0x266) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 0xF);
    M2C_FIELD(&data_0213bfcc, u16 *, 0x68) = (u16) M2C_FIELD(&data_0213ad98, u16 *, 0x1C);
    M2C_FIELD(&data_0213bfcc, u16 *, 0x6A) = (u16) M2C_FIELD(&data_0213ad98, u16 *, 0x1E);
}
