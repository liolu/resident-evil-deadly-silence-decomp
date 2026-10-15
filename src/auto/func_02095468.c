/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213caa0;

void func_02095468(s32 arg0) {
    if ((arg0 != 0xFF) && (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0)) {
        if ((u32) arg0 >= 0x80U) {
            if (M2C_FIELD(&data_0213bb18, u8 *, 0x222) == 0xFF) {
                M2C_FIELD(&data_0213bb18, u8 *, 0x222)  = (u8) arg0;
                M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = (s32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) & ~0xC00);
            } else {
                M2C_FIELD(&data_0213caa0, s8 *, 0x702) = 1;
            }
            return;
        }
        M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = (s32) ((M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) & ~0xC00) | 0x400);
        return;
    }
    M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = (s32) ((M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) & ~0xC00) | 0x400);
}
