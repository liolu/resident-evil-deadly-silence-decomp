/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02053e90(s32 a, u32 b);
typedef void (*Fn)(void);
extern Fn data_0211c730[];
extern s32 data_0213733c;
extern void *data_027e000c;

void func_020310c0(void) {
    u32 flag;

    flag = ((u8 *) data_027e000c)[0xA] & 0x40;
    if (flag == 0) {
        ((u8 *) data_027e000c)[0x90] = 1;
        if (((u8 *) data_027e000c)[0x93] != 0xA) {
            ((u8 *) data_027e000c)[0x93] = 0;
        }
        return;
    }
    data_0213733c = func_02053e90(0, flag);
    data_0211c730[((u8 *) data_027e000c)[0x92]]();
}
