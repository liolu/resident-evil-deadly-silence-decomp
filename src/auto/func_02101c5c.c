/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02100550(void);
void func_02105b9c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_02106088(M2C_UNK, M2C_UNK, M2C_UNK);

extern s32 data_02136b8c;

void func_02101c5c(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_ip;

    temp_ip = func_02100550();
    if ((data_02136b8c != -1) && ((u32) arg2 > 0x1CU)) {
        func_02105b9c(data_02136b8c, arg0, temp_ip + arg1, arg2);
        return;
    }
    func_02106088(arg0, temp_ip + arg1, arg2);
}
