/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;

void func_02094c68(void) {
    M2C_FIELD(&data_0213bb18, u8 *, 0x203) = (u8) (M2C_FIELD(&data_0213bb18, u8 *, 0x203) + 1);
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) {
        return;
    }
    if (((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1E) >> 0x1F) == 1) {
        M2C_FIELD(&data_0213bb18, u8 *, 0x2AB) = (u8) (M2C_FIELD(&data_0213bb18, u8 *, 0x2AB) + 1);
    }
}
