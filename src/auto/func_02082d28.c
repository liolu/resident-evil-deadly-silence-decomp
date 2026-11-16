/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    u8 pad0[0x90];
    u8 f90;
    u8 pad1;
    u8 f92;
    u8 pad2;
    s16 f94;
} Obj;

void func_0208358c(void **, u32);

void func_02082d28(void **arg0) {
    Obj *o = (Obj *) *arg0;

    if (o->f94 > 0) {
        o->f92 = 0xFF;
    } else {
        o->f90 = 2;
        func_0208358c(arg0, 0xA);
    }
}
