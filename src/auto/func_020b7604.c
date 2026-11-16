/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern void func_0200d47c(u16 a);
extern void func_0200d514(u16 a, u8 b, u16 c);
extern u8 data_0213aca8[];

void func_020b7604(s32 arg0, s32 arg1) {
    u8 *e;

    e = data_0213aca8 + arg0 * 12;
    if (e[1] == 0x40) {
        func_0200d47c((u16) * (s32 *) (e + 4));
        func_0200d514((u16) * (s32 *) (e + 4), e[2], (u16) arg1);
        e[1] = 0x80;
    }
}
