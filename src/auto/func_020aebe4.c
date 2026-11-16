/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_02143cc0[];
extern u8 data_02147cc0[];
extern u8 data_0214838c[];

void func_020aebe4(void) {
    u32 i;

    i = 0;
    do {
        *(u8 *) (data_02143cc0 + i * 12 + 0x4000 + 0x6cc) = 0;
        i++;
    } while (i < 32);
    *(u8 **) (data_02147cc0 + 0x84c) = data_0214838c;
}
