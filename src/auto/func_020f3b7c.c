/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020f39ec(void);
void func_020f3a40(M2C_UNK);
void func_020f3a98(M2C_UNK);

extern void (*data_021368d4)(s32);
extern void (*data_021368d8)(s32);
extern M2C_UNK data_02154390;

void func_020f3b7c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(&data_02154390, s32 *, 8) = arg0;
    M2C_FIELD(&data_02154390, s32 *, 0xC) = arg1;
    M2C_FIELD(&data_02154390, s32 *, 0x10) = arg2;
    func_020f39ec();
    if (arg3 == 0) {
        return;
    }
    data_021368d4 = func_020f3a98;
    data_021368d8 = func_020f3a40;
}
