/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct Obj {
    u8 pad0[0x30];
    s32 f30;
    s32 f34;
    s32 f38;
    s16 f3C;
    s16 f3E;
    s16 f40;
    u8 pad1[0x4F];
    u8 f91;
} Obj;

typedef void (*Handler)(void *);

extern Handler data_0211cfd8[];

void func_0205370c(void *arg0) {
    Obj *o = (Obj *) arg0;

    o->f3C = (s16) o->f30;
    o->f3E = (s16) o->f34;
    o->f40 = (s16) o->f38;
    data_0211cfd8[o->f91](arg0);
}
