/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_0209fbf0(s32 v);
typedef void (*Handler)(void *);
extern Handler data_0211cd30[];
extern u8 data_02143cc0[];
extern u8 data_027e009c[];
extern s32 data_027e0018;

void func_0204ded4(void *arg0) {
    s32 dx;
    s32 dy;

    func_0209fbf0(1);
    dx = *(s32 *) (data_02143cc0 + 0xF7C) - *(s32 *) (data_027e009c + 0x1C);
    if (dx < 0) {
        dx = 0 - dx;
    }
    dy = *(s32 *) (data_02143cc0 + 0xF74) - *(s32 *) (data_027e009c + 0x14);
    if (dy < 0) {
        dy = 0 - dy;
    }
    data_027e0018 = dy + dx;
    data_0211cd30[((u8 *) arg0)[0xA] & 7](arg0);
}
