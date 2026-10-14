/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_01ffd214(M2C_UNK, M2C_UNK);
void func_0201ea80(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_02144c34;

void func_02020a98(s32 arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0xA2);
    if ((u32) temp_r1 < 0xFU) {
        if ((u32) temp_r1 > 7U) {
            func_0201ea80(arg0, 0x20, 0x28);
        }
        func_01ffd214((s32) &data_02144c34, 0x40);
    } else {
        M2C_FIELD(arg0, s16 *, 0xA6) = 0;
        M2C_FIELD(arg0, s16 *, 0x182) = 0;
    }
    if ((u32) M2C_FIELD(arg0, u8 *, 0xA2) >= 0x13U) {
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0xA) = 4;
    }
}
