/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern void func_020956d8(s32);
extern void func_0209572c(void);
extern u8 data_0212036c[];
extern u8 data_0212041c[];
extern u8 data_0213ad48[];
extern u8 data_0213bb18[];

void func_02095798(u32 arg0) {
    u32 bit;

    if (data_0213ad48[4] != 0 && arg0 <= 0x20) {
        bit = ((u32) * (s32 *) (data_0213bb18 + 0x1FC) << 30) >> 31;
        func_020956d8(*(s32 *) (data_0212041c + bit * 44 + data_0212036c[arg0] * 4) + 0x1F4);
        func_0209572c();
    }
}
