/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02014d24(void);
void func_02085018(M2C_UNK);

extern M2C_UNK data_021375ac;

void func_020883f4(void) {
    func_02014d24();
    func_02085018(M2C_FIELD(&data_021375ac, s32 *, 0x64) + 0x4C8);
}
