/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213caa0;
extern M2C_UNK data_0213d0a0;

void func_020d8f3c(s32 arg0) {
    M2C_FIELD(&data_0213d0a0, u16 *, 0xFC) =
        (u16) ((M2C_FIELD(&data_0213d0a0, u16 *, 0xFC) & ~0xF000) | ((arg0 & 0xF) << 0xC));
    M2C_FIELD(&data_0213caa0, s8 *, 0x707) = 0;
    M2C_FIELD(&data_0213caa0, s8 *, 0x6FE) = 0;
    M2C_FIELD(&data_0213d0a0, u16 *, 0xFA) =
        (u16) ((M2C_FIELD(&data_0213d0a0, u16 *, 0xFA) & ~0xF000) |
               ((((u32) (M2C_FIELD(&data_0213d0a0, u16 *, 0xFC) << 0x10) >> 0x1C) & 0xF) << 0xC));
    M2C_FIELD(&data_0213caa0, s8 *, 0x700) = 0;
    M2C_FIELD(&data_0213caa0, s8 *, 0x701) = 0;
    M2C_FIELD(&data_0213caa0, s8 *, 0x702) = 0;
}
