/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02101ff4(M2C_UNK, M2C_UNK, M2C_UNK);
void func_0210205c(M2C_UNK, M2C_UNK, M2C_UNK);
void func_021046d4(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213d1c0;
extern M2C_UNK data_0213d234;
extern M2C_UNK data_0213d6a8;

void func_0200648c(void) {
    func_021046d4((s32) &data_0213d1c0, 0x8E8);
    func_0210205c((s32) &data_0213d234, 0, 0x400);
    func_02101ff4((s32) &data_0213d6a8, 0, 0x400);
}
