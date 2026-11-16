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

void func_020c922c(void) {
    Task *t = data_0213b890.f4c->f2f8;

    if (t->f18->f2c == ((t->f2c - 0x2000) & 0xFFFF)) {
        t->f2 = (u8) (t->f2 + 1);
    }
}
