/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02085c54(s32);                         /* extern */
extern M2C_UNK data_0211fdd4;

void func_0208e2c4(s32 arg0) {
    if (arg0 < 0x60) {
        func_02085c54(*((M2C_UNK *) ((s8 *) &data_0211fdd4 + (arg0 * 4))));
    }
}
