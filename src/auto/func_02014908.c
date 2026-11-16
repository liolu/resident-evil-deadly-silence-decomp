/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Handler)(void *);

typedef struct {
    u8 pad0[0x12];
    u8 active;
    u8 pad1;
    u8 kind;
    u8 rest[0x58 - 0x15];
} Obj;

extern Handler data_0211be88[];
extern M2C_UNK data_021486e0;
extern M2C_UNK data_021489a0;
extern M2C_UNK data_0214bcc0;

void func_02014908(void) {
    Obj *o;
    Obj *end;
    u8 n;

    n = M2C_FIELD(&data_0214bcc0, u8 *, 0x7A2);
    if (n == 0) {
        return;
    }
    o   = (Obj *) &data_021486e0;
    end = (Obj *) &data_021489a0;
    while (o < end) {
        if (o->active != 0) {
            data_0211be88[o->kind]((void *) o);
            n = (u8) (n - 1);
            if (n == 0) {
                return;
            }
        }
        o++;
    }
}
