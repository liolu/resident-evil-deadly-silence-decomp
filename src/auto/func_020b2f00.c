/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    u8 a;
    u8 b;
    u8 pad[10];
} Ent12;

extern void *data_0213daa8;
extern Ent12 data_0214838c[];

s32 func_020b2f00(void) {
    u8 *cur;
    u8 idx;
    u8 a;
    u8 b;

    cur                                           = (u8 *) data_0213daa8;
    idx                                           = cur[1];
    a                                             = cur[2];
    b                                             = cur[3];
    data_0213daa8                                 = cur + 4;
    *(u8 *) ((u8 *) data_0214838c + idx * 12)     = a;
    *(u8 *) ((u8 *) data_0214838c + idx * 12 + 1) = b;
    return 1;
}
