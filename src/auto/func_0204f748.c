/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"
typedef void (*Handler)(void *);
extern Handler data_0211ce70[];

typedef struct {
    u8 pad[0x91];
    u8 kind;
} Obj;

void func_0204f748(void *arg0) {
    u8 k = ((Obj *) arg0)->kind;
    if (k <= 2) {
        data_0211ce70[k](arg0);
    }
}
