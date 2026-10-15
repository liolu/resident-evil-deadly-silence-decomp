/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e45f8(void);
void func_020e4608(void);
void func_020e5ff8(void);
void func_02103a58(M2C_UNK);
void func_02103b00(M2C_UNK);

extern M2C_UNK data_02153054;
extern M2C_UNK data_02153110;

void func_020e6514(void) {
    if (M2C_FIELD(&data_02153054, s32 *, 8) == 1) {
        do {
            if (M2C_FIELD(&data_02153054, s32 *, 0x14) == 1) {
                func_02103a58(M2C_FIELD(&data_02153054, s32 *, 0x1E4));
            } else {
                func_02103a58((s32) &data_02153110);
            }
            func_020e4608();
            func_020e45f8();
            M2C_FIELD(&data_02153054, s32 *, 0x1E8) = (s32) (M2C_FIELD(&data_02153054, s32 *, 0x1E8) + 1);
            func_02103b00(0);
        } while (M2C_FIELD(&data_02153054, s32 *, 8) == 1);
    }
    func_020e5ff8();
}
