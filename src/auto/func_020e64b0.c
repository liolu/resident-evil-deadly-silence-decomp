/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e45d8(void);
void func_02103a58(M2C_UNK);
void func_02103b00(M2C_UNK);

extern M2C_UNK data_02153054;

void func_020e64b0(void) {
    if (M2C_FIELD(&data_02153054, s32 *, 0x10) == 1) {
        do {
            func_02103a58(M2C_FIELD(&data_02153054, s32 *, 0x1E4));
            func_020e45d8();
            M2C_FIELD(&data_02153054, s32 *, 0x1EC) = (s32) (M2C_FIELD(&data_02153054, s32 *, 0x1EC) + 1);
            func_02103b00(0);
        } while (M2C_FIELD(&data_02153054, s32 *, 0x10) == 1);
    }
    M2C_FIELD(&data_02153054, s32 *, 0x14) = 1;
}
