/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02090a10(void *arg0, u32 arg1, u32 arg2) {
    u32 i;
    u32 bit;

    for (i = 0; i < arg1; i++) {
        bit = 1 << i;
        if (arg2 & bit) {
            *(u32 *) ((u8 *) arg0 + 0x74) &= ~bit;
        } else {
            *(u32 *) ((u8 *) arg0 + 0x74) |= bit;
        }
    }
}
