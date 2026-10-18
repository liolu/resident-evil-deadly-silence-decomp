/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213c038;

void func_020876a8(s32 arg0) {
    if (arg0 < 0x17) {
        *((u8 *) ((s8 *) &data_0213c038 + (arg0 * 2))) = (*((u8 *) ((s8 *) &data_0213c038 + (arg0 * 2))) & ~0xF) | 1;
    }
}
