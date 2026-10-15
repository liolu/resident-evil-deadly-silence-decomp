/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02105528(void);

extern s16 data_02158ba4;

void func_021055ec(s32 arg0, s32 arg1) {
    if (((u32) ((arg1 & 0x7F00) << 8) >> 0x10) == 0x10) {
        data_02158ba4 = 1;
        return;
    }
    func_02105528();
}
