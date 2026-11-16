/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct Obj {
    u8 pad0[4];
    s32 f4;
    u8 *f8;
} Obj;

typedef struct Msg {
    s32 f0;
    s32 f4;
    u8 *f8;
    u8 pad[48];
} Msg;

typedef void (*Handler)(Msg *);

extern Handler data_0211d2b0[];

void func_02056e60(Obj *arg0) {
    Msg m;
    u8 *p;

    p    = arg0->f8;
    m.f8 = p;
    m.f4 = arg0->f4;
    data_0211d2b0[*p - 0x80](&m);
}
