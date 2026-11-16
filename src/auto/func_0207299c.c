/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void *);
extern Handler data_0211d9fc[];

typedef struct {
    u8 pad[1];
    u8 kind;
} Obj;

s32 func_0207299c(void *arg0) {
    data_0211d9fc[((Obj *) arg0)->kind](arg0);
    return 1;
}
