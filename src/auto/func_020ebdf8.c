/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 data_02154328;
extern s8 *data_02154324;
extern s8 *data_02154330;
extern s8 data_02133464[];
extern s8 data_02131528[];

void func_020ebdf8(void) {
    s32 i;
    s8 *p;
    s8 *src;

    if (data_02154328 != 0) {
        return;
    }
    src           = data_02133464;
    p             = (s8 *) (((s32) src + 0x1F) & ~0x1F);
    data_02154324 = p;
    i             = 0x400;
    do {
        p[i] = src[i];
        i--;
    } while (i >= 0);
    src           = data_02131528;
    p             = (s8 *) (((s32) src + 0x1F) & ~0x1F);
    data_02154330 = p;
    i             = 0x1000;
    do {
        p[i] = src[i];
        i--;
    } while (i >= 0);
    data_02154328 = 1;
}
