/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"
typedef void (*Handler)(void *);
extern Handler data_0211c2c8[];

typedef struct {
    u8 pad[0x91];
    u8 kind;
} Obj;

void func_0201f4dc(void *arg0) {
    u8 k = ((Obj *) arg0)->kind;
    if (k <= 3) {
        data_0211c2c8[k](arg0);
    }
}
