/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} T12;

M2C_UNK func_0208b1e8(T12 *, s32 *, s32 *);     /* extern */
M2C_UNK func_0208c730(void *);                      /* extern */
M2C_UNK func_02091934(T12 *);                   /* extern */

void func_0208c774(void *arg0) {
    T12 loc;
    s32 o0;
    s32 o1;

    loc = *(T12 *) ((u8 *) arg0 + 0x308);
    func_02091934(&loc);
    func_0208b1e8(&loc, &o0, &o1);
    M2C_FIELD(arg0, s16 *, 0x304) = (s16) o0;
    M2C_FIELD(arg0, s16 *, 0x306) = (s16) o1;
    func_0208c730((u8 *) arg0 + 0x304);
}
