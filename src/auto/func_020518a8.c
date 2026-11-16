/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef s32 (*Fn)(void);
extern Fn data_0211cf60[];
extern u8 data_02143cc0[];
extern u8 *data_027e000c;

s32 func_020518a8(void) {
    s32 r;

    r = data_02143cc0[0xF4D] & 1;
    if (r != 0) {
        goto end;
    }
    r = data_0211cf60[data_027e000c[0x91]]();
end:
    return r;
}
