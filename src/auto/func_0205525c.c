/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_020bb6ec(u32);
void func_020bb780(u8, s32);
extern void *data_027e000c;

void func_0205525c(void) {
    switch (((u8 *) data_027e000c)[0x93]) {
        case 0:
            ((u8 *) data_027e000c)[0xA2] = 0;
            ((u8 *) data_027e000c)[0xA3] = 0;
            ((u8 *) data_027e000c)[0xA1] = 0;
            ((u8 *) data_027e000c)[0x93] = 1;
            ((u8 *) data_027e000c)[0x98] = 7;
            func_020bb6ec(0x8000);
        /* fall through */
        case 1:
            func_020bb780((u8) ((*(u16 *) ((u8 *) data_027e000c + 0xEC) & 1) ? 3 : 1), 0x200);
            break;
        default:
            break;
    }
}
