/* compiler: 1.2/sp2p3 */
#include "m2c.h"
extern u8 *data_0211e864[];

u8 func_02079148(u32 arg0, u32 arg1) {
    u8 *p = data_0211e864[arg0];
loop_1:
    if (arg1 == p[1]) {
        goto done;
    }
    p += 10;
    if (*p != 0xF0) {
        goto loop_1;
    }
done:
    return *p;
}
