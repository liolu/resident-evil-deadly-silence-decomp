/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0212ca9c[];
extern void *data_027e000c;
extern s32 data_027e0018;

void func_020382e4(void) {
    void *obj = data_027e000c;

    data_027e0018 = M2C_FIELD(obj, s32 *, 0x18C);
    data_0212ca9c[M2C_FIELD(obj, u8 *, 0xA) & 7]();
}
