/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void *);
extern Handler data_0213ae98[];

typedef struct {
    u8 pad[0x91];
    u8 kind;
} Obj;

void func_020a7778(void *arg0) {
    data_0213ae98[((Obj *) arg0)->kind](arg0);
}
