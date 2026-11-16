/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Handler)(void *);
typedef struct {
    Handler h[11];
} Table44;

extern Table44 data_0212e938;

void func_020ab404(void *arg0) {
    Table44 loc;

    loc = data_0212e938;
    loc.h[((u8 *) arg0)[0x93]](arg0);
}
