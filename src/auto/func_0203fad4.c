/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 data_027e0024;
extern u8 *data_027e000c;
extern u8 data_0211ca90;

typedef void (*Fn48)(void);

s32 func_020d9650(void);

void func_0203fad4(void) {
    s32 r0;

    r0            = func_020d9650();
    data_027e0024 = r0;
    if (((s32) r0 >> 1) == 0) {
        *(s16 *) (data_027e000c + 0x17C) = (s16) (*(s16 *) (data_027e000c + 0x17C) & 0xFFFE);
        *(s16 *) (data_027e000c + 0x17C) = (s16) (*(s16 *) (data_027e000c + 0x17C) | (data_027e0024 & 1));
    }
    ((Fn48 *) &data_0211ca90)[data_027e000c[0x92]]();
}
