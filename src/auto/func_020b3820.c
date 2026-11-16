/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_020b39e4(void *, s32);
extern u8 data_0213be30[];

void func_020b3820(u8 *arg0) {
    if (arg0[0] != 0x55) {
        func_020b39e4(data_0213be30, arg0[3]);
        return;
    }
    func_020b39e4(data_0213be30, arg0[3] + 0x100);
}
