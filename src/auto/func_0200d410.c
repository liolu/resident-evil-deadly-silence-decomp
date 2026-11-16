/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s32 type;
    s32 a;
    s32 b;
    s32 c;
} Msg;

extern Msg data_021372ac;
void func_0200df40(Msg *);

void func_0200d410(s32 arg0, s32 arg1, s32 arg2) {
    Msg *m = &data_021372ac;

    m->a    = arg0;
    m->type = 0xB;
    m->b    = arg1;
    m->c    = arg2;
    func_0200df40(m);
}
