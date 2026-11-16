/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u32 data_0211fce0[];
extern u32 data_0211fdd4[];

typedef struct {
    u8 pad[22];
    u16 f22;
} Obj;

u32 func_0208e01c(Obj *arg0) {
    u8 i;

    for (i = 0; i < 10; i++) {
        if (data_0211fce0[i] > arg0->f22) {
            break;
        }
    }
    return arg0->f22 * data_0211fdd4[i + 35];
}
