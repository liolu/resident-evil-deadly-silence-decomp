/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    u8 pad[0x538];
    u8 *tbl;
    u8 pad2[4];
    u8 cnt;
} Obj;

extern M2C_UNK data_02147cc0;

s32 func_02074d40(void) {
    Obj *o = (Obj *) &data_02147cc0;
    u8 *t;
    s32 n;
    s32 i;

    t = o->tbl;
    n = o->cnt;
    i = 0;
    goto check;
next:
    if (t[i * 2] == 0) {
        return i;
    }
    i++;
check:
    if (i < n) {
        goto next;
    }
    return -1;
}
