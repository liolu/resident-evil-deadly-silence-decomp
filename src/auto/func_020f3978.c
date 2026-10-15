/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020f363c(void);
void func_020f3834(M2C_UNK);
void func_020f38c4(M2C_UNK, M2C_UNK);

extern void (*data_021368cc)(s32, s32);
extern void (*data_021368d0)(s32);
extern M2C_UNK data_02154374;

void func_020f3978(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(&data_02154374, s32 *, 0xC)  = arg0;
    M2C_FIELD(&data_02154374, s32 *, 0x10) = arg1;
    M2C_FIELD(&data_02154374, s32 *, 0x14) = arg2;
    M2C_FIELD(&data_02154374, s32 *, 0x18) = arg3;
    func_020f363c();
    if (arg4 == 0) {
        return;
    }
    data_021368cc = func_020f38c4;
    data_021368d0 = func_020f3834;
}
