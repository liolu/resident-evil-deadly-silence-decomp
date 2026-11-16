/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef s32 (*Fn)(void *);
extern Fn data_0211d280[];

s32 func_02059540(void *arg0) {
    u8 k;
    s32 r;

    k = *(u8 *) *(u8 **) ((u8 *) arg0 + 8);
    if (k >= 1 && k <= 0xB) {
        r                          = data_0211d280[k](arg0);
        *(u8 **) ((u8 *) arg0 + 8) = *(u8 **) ((u8 *) arg0 + 8) + r;
    }
    return 0;
}
