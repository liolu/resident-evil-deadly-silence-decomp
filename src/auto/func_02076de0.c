/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    u8 used;
    u8 count;
    u8 pad[2];
    s32 res;
    u8 rest[12];
} Slot;

extern Slot data_0213b610[];
extern void func_02070438(s32);
extern void func_0207690c(void *);
extern void func_020f7f1c(s32);

void func_02076de0(u8 *arg0) {
    u8 idx;
    Slot *s;

    idx   = *arg0;
    *arg0 = 0;
    if (idx == 0) {
        return;
    }
    s = &data_0213b610[idx];
    if (s->used == 0) {
        return;
    }
    s->count = s->count - 1;
    if (s->count == 0) {
        func_020f7f1c(s->res);
        func_02070438(s->res);
        func_0207690c(s);
    }
}
