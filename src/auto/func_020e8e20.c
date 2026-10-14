/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_021338a4;
extern M2C_UNK data_021338a8;

s32 func_020e8e20(s32 arg0, s32 *arg1) {
    *arg1 = (arg0 * 0x3000) + (s32) &data_021338a8;
    return *((M2C_UNK *)((s8 *)&data_021338a4 + (arg0 * 4)));
}
