/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    u32 f0;
    u8 f4;
    u8 pad5[2];
    u8 f7;
} Obj0;
typedef struct {
    u8 pad[148];
    s16 f94;
    u8 f96;
} Obj1;
typedef void (*Handler)(Obj0 *, Obj1 *);
extern Handler data_02119230[];

void func_02002c64(Obj0 *arg0, Obj1 *arg1) {
    if ((arg0->f4 == 2) && (arg0->f0 > 0x2328U)) {
        arg1->f96 = (u8) (arg1->f96 - 1);
        arg1->f94 = (s16) (arg1->f94 + 0xA);
    }
    data_02119230[arg0->f7](arg0, arg1);
}
