/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} T12;

typedef struct {
    u8 kind;
    u8 pad[3];
    T12 p4;
    T12 p10;
} Ent;

void *func_0208fe14(void *);
void func_0208fdbc(void *);

void func_0208fe60(void *arg0, void *arg1, void *arg2) {
    Ent *e;

    e = (Ent *) func_0208fe14(arg0);
    if (e != NULL) {
        func_0208fdbc(e);
        if (e->kind == 1) {
            e->p4  = *(T12 *) arg1;
            e->p10 = *(T12 *) arg2;
            return;
        }
        M2C_FIELD(e, s32 *, 0xC)  = 0;
        M2C_FIELD(e, s32 *, 8)    = (s32) M2C_FIELD(e, s32 *, 0xC);
        M2C_FIELD(e, s32 *, 4)    = (s32) M2C_FIELD(e, s32 *, 8);
        M2C_FIELD(e, s32 *, 0x18) = 0;
        M2C_FIELD(e, s32 *, 0x14) = (s32) M2C_FIELD(e, s32 *, 0x18);
        M2C_FIELD(e, s32 *, 0x10) = (s32) M2C_FIELD(e, s32 *, 0x14);
    }
}
