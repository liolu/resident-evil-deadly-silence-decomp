/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void *);
extern Handler data_0211c0e4[];

typedef struct {
    u8 pad[0x92];
    u8 kind;
} Obj;

void func_0201cd60(void *arg0) {
    data_0211c0e4[((Obj *) arg0)->kind](arg0);
}
