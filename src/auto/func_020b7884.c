/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    u8 a;
    u8 b;
    u16 pad;
    s32 f4;
    s32 f8;
} Slot;

void func_0200d4a0(u16, s32);
void func_0200d4e8(u16);
void func_020b86d0(s32);
extern Slot data_0213aca8[];

void func_020b7884(s32 arg0) {
    Slot *s;

    s = &data_0213aca8[arg0];
    if (s->f4 != 0) {
        func_0200d4a0((u16) s->f4, 0);
        func_0200d4e8((u16) arg0);
        if (s->f8 != 0) {
            func_020b86d0(s->f8);
            s->f8 = 0;
        }
        s->f4 = 0;
        s->a  = 0;
        s->b  = 0;
    }
}
