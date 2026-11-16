/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct Task {
    u8 pad0[2];
    u8 f2;
    u8 pad1[0x13];
    s16 f16;
    struct Task *f18;
    u8 pad2[0x10];
    u16 f2c;
} Task;

typedef struct Ctx {
    u8 pad0[0x2F8];
    Task *f2f8;
} Ctx;

typedef struct Global {
    u8 pad0[0x4C];
    Ctx *f4c;
} Global;

extern Global data_0213b890;

void func_020c91ec(void) {
    Task *t = data_0213b890.f4c->f2f8;
    Task *s = t->f18;

    t->f2c = (u16) (t->f2c - 0x800);
    if (s->f16 == 1) {
        data_0213b890.f4c->f2f8->f2 = (u8) (data_0213b890.f4c->f2f8->f2 + 1);
    }
}
