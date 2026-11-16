/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Handler)(void *);
extern Handler data_0211c358[];
void func_02021cdc(void *, s32);

void func_02021d04(void *arg0) {
    s32 temp_r1;
    u8 temp_r2;

    *(u8 *) ((u8 *) arg0 + 0x194) = 0;
    *(u8 *) ((u8 *) arg0 + 0xA3)  = 0;
    temp_r1                       = *(u16 *) ((u8 *) arg0 + 0x198) & 0x80;
    if (temp_r1 != 0) {
        *(u8 *) ((u8 *) arg0 + 0xA2) = 0;
    }
    temp_r2 = *(u8 *) ((u8 *) arg0 + 0xA);
    if (temp_r2 == 0x80) {
        func_02021cdc(arg0, temp_r1);
        return;
    }
    data_0211c358[temp_r2](arg0);
}
