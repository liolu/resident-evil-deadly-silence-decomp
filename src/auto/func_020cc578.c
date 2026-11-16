/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct Global {
    u8 pad0[0x4C];
    u8 *f4c;
} Global;

extern Global data_0213b890;

s32 func_020cc578(void) {
    u32 i;
    u8 *c;

    for (i = 0; i < 4; i++) {
        c = data_0213b890.f4c + i;
        if (c[0x578] != c[0x574]) {
            return 0;
        }
    }
    return 1;
}
