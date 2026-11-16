/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void *);
extern Handler data_0211cd6c[];

typedef struct {
    u8 pad[0x92];
    u8 kind;
} Obj;

void func_0204d990(void *arg0) {
    data_0211cd6c[((Obj *) arg0)->kind](arg0);
}
