/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_021060b8(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_02137264;

void func_0200502c(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_021060b8(arg0, (s32) (data_02137264 + 0x8BF64), 0x200);
    }
    if (arg1 != 0) {
        func_021060b8(arg1, (s32) (data_02137264 + 0x8C164), 0xC000);
    }
    M2C_FIELD(data_02137264, s8 *, 2) = 1;
}
