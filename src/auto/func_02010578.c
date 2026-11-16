/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void *);
extern Handler data_0211bb5c[];

typedef struct {
    u8 pad[0xe5];
    u8 kind;
} Obj;

void func_02010578(void *arg0) {
    data_0211bb5c[((Obj *) arg0)->kind](arg0);
}
