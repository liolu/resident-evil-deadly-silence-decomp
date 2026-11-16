/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 *data_027e000c;
extern u8 data_0213bdcc[];
u8 func_02075738(s32, s32);

void func_020518f0(void) {
    u8 *p;

    p = data_027e000c;
    if (p[0x92] == 0) {
        if (func_02075738(1, 0x200) != 0) {
            data_027e000c[0x92] = data_027e000c[0x92] + 1;
        }
    } else {
        if ((*(s32 *) (data_0213bdcc + 0x44) & 0x20000) == 0) {
            p[0xA]              = p[0xA] | 0x20;
            data_027e000c[0x91] = 0;
        }
    }
}
