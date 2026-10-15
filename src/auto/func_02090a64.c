/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02090af4(M2C_UNK);

extern s32 data_02137e88;

void func_02090a64(void) {
    func_02090af4(data_02137e88);
    if (data_02137e88 != 0) {
        data_02137e88 -= 1;
    }
}
