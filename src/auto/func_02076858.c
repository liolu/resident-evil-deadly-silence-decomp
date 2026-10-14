/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213ad98;

void func_02076858(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0) = (u8) (M2C_FIELD(&data_0213ad98, u8 *, 0) + 1);
    switch ((s32) M2C_FIELD(&data_0213ad98, u8 *, 0)) { /* irregular */
    case 5:
    case 6:
        M2C_FIELD(arg0, u8 *, 0) = (u8) (M2C_FIELD(arg0, u8 *, 0) - 5);
        break;
    case 15:
        M2C_FIELD(arg0, u8 *, 0) = (u8) (M2C_FIELD(arg0, u8 *, 0) - 0xF);
        break;
    case 16:
    case 17:
        M2C_FIELD(arg0, u8 *, 0) = (u8) (M2C_FIELD(arg0, u8 *, 0) - 0xD);
        break;
    }
    M2C_FIELD(arg0, u8 *, 1) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 2) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 2);
}
