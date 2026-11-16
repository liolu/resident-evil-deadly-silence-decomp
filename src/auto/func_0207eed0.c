/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s16 a[3];
    s32 b[3];
    s32 c[2];
} Tmp;

extern void func_020848ec(void *, s16 *, s32 *);
extern void func_02082488(void *, s32, s32, s32);

void func_0207eed0(void *arg0) {
    Tmp t;

    t.a[0] = 0;
    t.a[1] = 0x800;
    t.a[2] = 0;
    t.b[0] = 0x796;
    t.b[1] = 0;
    t.b[2] = -0x40;
    func_020848ec(arg0, t.a, t.b);
    func_02082488(arg0, 0x15, 0, 0);
    *(u8 *) (*(u8 **) arg0 + 0x93) = 0;
    *((u8 *) arg0 + 5)             = *((u8 *) arg0 + 5) | 8;
    (*(u8 **) arg0)[0x92]          = (*(u8 **) arg0)[0x92] + 1;
}
