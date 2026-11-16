/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    u8 kind;
    u8 flag;
} Obj;

extern M2C_UNK data_0213be00;
s32 func_020b39e4(M2C_UNK *, M2C_UNK);

void func_0207518c(void *arg0) {
    Obj *o = arg0;

    if (o->kind == 5) {
        if (func_020b39e4(&data_0213be00, 0x7A) != 0) {
            o->flag = 0xFF;
        }
    }
}
