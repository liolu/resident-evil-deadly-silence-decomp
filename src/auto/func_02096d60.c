/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s16 pad0;
    s16 pad2;
    s16 px;
    s16 py;
    s16 cx;
    s16 cy;
} Pos37;

void func_02096d60(Pos37 *arg0, s16 arg1, s16 arg2) {
    s16 dx;
    s16 dy;
    s32 ax;
    s32 ay;

    dx = arg1 - arg0->cx;
    dy = arg2 - arg0->cy;
    ax = dx >= 0 ? dx : -dx;
    if (ax > 10) {
        arg0->px = arg0->px + (dx >> 2);
    } else {
        arg0->px = arg1;
    }
    ay = dy >= 0 ? dy : -dy;
    if (ay > 10) {
        arg0->py = arg0->py + (dy >> 2);
    } else {
        arg0->py = arg2;
    }
}
