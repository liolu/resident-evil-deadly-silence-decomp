/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 *data_027e000c;
extern void (*data_0211c8ac[])(void);
extern void func_0203343c(void);

void func_0203832c(void) {
    if ((*(s16 *) (*(u8 **) (data_027e000c + 0x9C) + 0x94) & 0x8000) != 0) {
        data_027e000c[0x90] = 3;
        data_027e000c[0x91] = 1;
        data_027e000c[0x92] = 0;
        data_027e000c[0x93] = 0;
        func_0203343c();
        data_027e000c[0x96]             = 1;
        *(s16 *) (data_027e000c + 0x94) = -1;
    } else {
        data_0211c8ac[data_027e000c[0x92]]();
    }
}
