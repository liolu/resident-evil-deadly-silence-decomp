/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020b7884(M2C_UNK);

extern M2C_UNK data_0213bdcc;

void func_020b67e8(void) {
    func_020b7884(0);
    func_020b7884(1);
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & ~0x20000);
}
