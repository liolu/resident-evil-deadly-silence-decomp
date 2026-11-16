/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Handler)(u8 *);
extern Handler data_0211ce8c[];
s16 func_02075738(u32, u32);

void func_020502bc(u8 *arg0) {
    if (arg0[0xa] & 0x20) {
        arg0[0x91] = 0;
        return;
    }
    *(s16 *) (arg0 + 0x182) = func_02075738(1, 0x80);
    data_0211ce8c[arg0[0x92]](arg0);
}
