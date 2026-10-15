/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;
extern M2C_UNK data_0213ad30;

s32 func_02089df0(void) {
    if (M2C_FIELD(&data_021375ac, s8 *, 0x62) != 0) {
        return 0;
    }
    if (M2C_FIELD(&data_021375ac, u8 *, 1) == 0) {
        return 0;
    }
    if (M2C_FIELD(&data_021375ac, u8 *, 0x23) == 0) {
        return 0;
    }
    if (M2C_FIELD(&data_021375ac, u8 *, 3) != 0) {
        return 0;
    }
    if (M2C_FIELD(&data_021375ac, s8 *, 0x10) != 0) {
        return 0;
    }
    if (M2C_FIELD(&data_021375ac, s8 *, 0xE) != 0) {
        return 0;
    }
    if (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x179) == 0) {
        return 0;
    }
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & ~8) {
        return 0;
    }
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 8) {
        return 1;
    }
    return 0;
}
