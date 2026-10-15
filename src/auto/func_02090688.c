/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_021061d8(M2C_UNK, M2C_UNK, M2C_UNK);

extern s32 data_02137b88;

void func_02090688(void) {
    func_021061d8((s32) &data_02137b88, 0, 0x300);
    data_02137b88 = 0x20000;
}
