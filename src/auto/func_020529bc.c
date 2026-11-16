/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Fn)(void);

extern Fn data_0212cfa0[];
extern Fn data_0212cfd8[];
extern u8 data_02143cc0[];
extern u8 *data_027e000c;

void func_020529bc(void) {
    if (!(data_02143cc0[0xF4D] & 1)) {
        data_0212cfd8[data_027e000c[0x92]]();
        return;
    }
    data_0212cfa0[data_027e000c[0x92]]();
}
