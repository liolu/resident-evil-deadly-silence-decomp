/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_02018204(s32, s32, s32, M2C_UNK *, s32 *, s32);
s32 func_02087f48(void);
extern M2C_UNK data_027e007c;

void func_0207b53c(void) {
    s32 arr[5];

    arr[0] = 0x500;
    arr[1] = ((func_02087f48() - 0x10) << 5) - 0x900;
    arr[2] = (func_02087f48() - 0x10) << 5;
    func_02018204(0, 0x10, 0, &data_027e007c, arr, 0);
}
