/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02092ec4(void *arg0);
void func_021060b8(void *arg0, void *arg1, u32 arg2);

void func_02092e9c(void *arg0) {
    u8 buf[0x28];

    func_021060b8(arg0, buf, 0x28);
    func_02092ec4(buf);
}
