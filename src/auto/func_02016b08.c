/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 func_01ff8ec4(u8 a, u8 b, s16 c, s32 d, s32 *e, s32 f, s32 g);
extern s32 data_027e0018;
extern s32 data_027e0054[];

void func_02016b08(void *arg0) {
    data_027e0054[0] = *(s16 *) ((u8 *) arg0 + 0x20);
    data_027e0054[1] = *(s16 *) ((u8 *) arg0 + 0x22);
    data_027e0054[2] = *(s16 *) ((u8 *) arg0 + 0x24);
    data_027e0018 = func_01ff8ec4(*((u8 *) arg0 + 4), *((u8 *) arg0 + 5), *(s16 *) ((u8 *) arg0 + 0x16), 0, data_027e0054, 0,
                                  *(s32 *) ((u8 *) arg0 + 0x84));
}
