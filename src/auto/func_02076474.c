/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    s32 a0;
    s32 a4;
    s32 a8;
    u8 kind;
    u8 pad[3];
    s32 a10;
} Entry;

typedef struct {
    u8 count;
    u8 idx;
    u8 pad[2];
    Entry ent[16];
} Table;

extern Table data_0213b4cc;

s32 func_02076474(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Table *t;
    Entry *e;
    u8 i;

    t = &data_0213b4cc;
    if (t->count >= 0x10U) {
        return 0;
    }
    i        = t->idx;
    e        = &t->ent[i];
    e->a0    = arg1;
    e->a4    = arg2;
    e->a8    = arg3;
    e->kind  = 3;
    e->a10   = arg0;
    t->count = (u8) (t->count + 1);
    t->idx   = (u8) ((t->idx + 1) & 0xF);
    return 1;
}
