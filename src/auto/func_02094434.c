/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213bd18;

void func_02094434(s32 arg0) {
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x47) << 0x1F) >> 0x1F) != 0) {
        M2C_FIELD(&data_0213bd18, u16 *, 4) = (u16) (M2C_FIELD(&data_0213bd18, u16 *, 4) + 0x384);
    }
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x47) << 0x1E) >> 0x1F) != 0) {
        M2C_FIELD(&data_0213bd18, u16 *, 6) = (u16) (M2C_FIELD(&data_0213bd18, u16 *, 6) + 0x258);
    }
}
