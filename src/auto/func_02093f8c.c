/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bd18;

void func_02093f8c(void) {
    s32 temp_ip;
    s32 temp_ip_2;

    temp_ip                                 = M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) & ~0x4000;
    M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = temp_ip;
    if (M2C_FIELD(&data_0213bd18, u16 *, 4) != 0) {
        M2C_FIELD(&data_0213bd18, u16 *, 4)     = (u16) (M2C_FIELD(&data_0213bd18, u16 *, 4) - 1);
        M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = (s32) (temp_ip | 0x4000);
    }
    temp_ip_2                               = M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) & ~0x8000;
    M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = temp_ip_2;
    if (M2C_FIELD(&data_0213bd18, u16 *, 6) != 0) {
        M2C_FIELD(&data_0213bd18, u16 *, 6)     = (u16) (M2C_FIELD(&data_0213bd18, u16 *, 6) - 1);
        M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = (s32) (temp_ip_2 | 0x8000);
    }
}
