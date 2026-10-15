/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c7488(void) {
    u8 temp_r1;

    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x20) == 0x1E) {
        temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEF);
        switch (temp_r1) {                          /* irregular */
            case 2:
                M2C_FIELD(&data_0213b890, s8 *, 0x23)                           = 2;
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xE8) = 0;
                break;
            case 0:
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x4B) = 0;
                M2C_FIELD(&data_0213b890, s8 *, 0x23)                           = 4;
                break;
            case 1:
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x4B) = 1;
                M2C_FIELD(&data_0213b890, s8 *, 0x23)                           = 4;
                break;
        }
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x20) == 0) {
        M2C_FIELD(&data_0213b890, s8 *, 0x23)                           = 2;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xE8) = 0;
    }
}
