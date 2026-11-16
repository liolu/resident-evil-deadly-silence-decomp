/* compiler: 1.2/sp2p3 */
#include "m2c.h"
extern u8 *data_0213daa8;
void func_020b3a44(u8 arg0);

u8 func_020593e0(void *arg0) {
    u8 *p = *(u8 **) ((u8 *) arg0 + 8);
    u8 r4;
    data_0213daa8 = p + 2;
    r4            = p[1];
    func_020b3a44(p[2]);
    return r4;
}
