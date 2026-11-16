/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Q;

typedef struct {
    Q x;
    Q y;
} P;

void func_02017bac(void *arg0) {
    P *src;

    src = *(P **) ((u8 *) arg0 + 0x84);
    if ((src != NULL) && ((((s32 *) src)[5] + ((s32 *) src)[6] + ((s32 *) src)[7]) != 0)) {
        *(P *) ((u8 *) arg0 + 0x30) = *src;
        return;
    }
    *(P *) ((u8 *) arg0 + 0x30) = *(P *) ((u8 *) arg0 + 0x64);
}
