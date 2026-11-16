/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct Ctx {
    u8 f0;
    u8 f1;
} Ctx;

typedef struct Global {
    u8 pad0[8];
    u8 f8;
    u8 pad1[0x17];
    u8 f20;
    u8 pad2[0x2B];
    Ctx *f4c;
} Global;

typedef void (*Handler)(void);

extern Handler data_02125020[];
extern Global data_0213b890;

void func_020c2a2c(void) {
    data_02125020[data_0213b890.f20]();
    data_0213b890.f8 = data_0213b890.f4c->f1;
}
