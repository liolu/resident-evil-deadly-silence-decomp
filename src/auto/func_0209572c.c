/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;

void func_0209572c(s32 arg0) {
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) {
        return;
    }
    M2C_FIELD(&data_0213bb18, s32 *, 0x210) = arg0;
    M2C_FIELD(&data_0213bb18, s32 *, 0x1CC) = (s32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1CC) + arg0);
    M2C_FIELD(&data_0213bb18, s32 *, 0x214) = 0x1E;
}
