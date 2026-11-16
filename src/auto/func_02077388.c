/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    u16 key;
    u8 cnt;
    u8 pad[5];
} Ent77;

u32 func_02077388(u8 *arg0, s16 arg1) {
    Ent77 *p;
    Ent77 *end;

    end = (Ent77 *) (arg0 + 0x180);
    if ((u32) (arg1 - 0x6B) > 0x4EU) {
        p = (Ent77 *) (arg0 + 8);
        goto cond1;
    body1:
        if (p->cnt != 0) {
            if (p->key == arg1) {
                p->cnt = (u8) (p->cnt + 1);
                return (u32) p;
            }
        }
        p++;
    cond1:
        if (p < end) {
            goto body1;
        }
    }
    p = (Ent77 *) (arg0 + 8);
    goto cond2;
body2:
    if (p->cnt == 0) {
        p->cnt = 1;
        p->key = arg1;
        return (u32) p;
    }
    p++;
cond2:
    if (p < end) {
        goto body2;
    }
    return 0;
}
