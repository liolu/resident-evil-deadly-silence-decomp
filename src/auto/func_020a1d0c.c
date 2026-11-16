/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern void func_0200ed94(void);
extern u8 data_02143cc0[];
extern u8 data_02144cc0[];
extern u8 data_02147cc0[];
extern u8 *data_0214d068[];

void func_020a1d0c(void) {
    u8 saved;
    u8 *p;

    if (data_02147cc0[0x542] == 4) {
        saved              = data_02143cc0[0xE];
        data_02143cc0[0xE] = 1;
        func_0200ed94();
        data_02143cc0[0xE] = saved;
        p                  = data_0214d068[*(u16 *) (*(u8 **) (data_02144cc0 + 0xDC) + 4)];
        p[8]               = p[8] & 0xFE;
    }
}
