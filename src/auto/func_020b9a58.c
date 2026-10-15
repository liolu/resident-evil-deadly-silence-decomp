/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213acfc;

void func_020b9a58(s32 arg0) {
    M2C_FIELD(&data_0213acfc, s8 *, 0x1A)  = 1;
    M2C_FIELD(&data_0213acfc, s16 *, 0x18) = 0;
    switch (arg0) {                                 /* irregular */
        case 3:
            M2C_FIELD(&data_0213acfc, s8 *, 0x1C) = 6;
            return;
        case 1:
            M2C_FIELD(&data_0213acfc, s8 *, 0x1C) = 0;
            return;
        case 2:
            M2C_FIELD(&data_0213acfc, s8 *, 0x1C) = 5;
            return;
    }
}
