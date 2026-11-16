/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void *);
extern Handler data_0211cadc[];

typedef struct {
    u8 pad[0x93];
    u8 kind;
} Obj93;

void func_020422f4(void *arg0) {
    data_0211cadc[((Obj93 *) arg0)->kind](arg0);
}
