/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02010e3c(M2C_UNK, M2C_UNK);
void func_02010ebc(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0211bcec;
extern M2C_UNK data_0211bd00;

void func_02010f9c(s32 arg0) {
    func_02010ebc((s32) &data_0211bcec, arg0);
    func_02010e3c((s32) &data_0211bd00, arg0);
}
