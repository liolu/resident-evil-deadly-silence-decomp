/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_02143cc0[];
extern u8 *data_027e000c;
extern void (*data_0211cf30[])(void);
void func_020518f0(s32);

void func_02051a24(void) {
    s32 t;

    t = data_02143cc0[0xf4d] & 1;
    if (t != 0) {
        func_020518f0(t);
        return;
    }
    data_0211cf30[data_027e000c[0x92]]();
}
