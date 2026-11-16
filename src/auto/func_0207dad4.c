/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} S16;

extern s32 func_02084b48(void *obj, S16 *cfg);
extern s32 func_0211851c(s32 v, s32 k);
extern S16 data_0212d64c;

void func_0207dad4(void *arg0) {
    S16 loc = *(S16 *) &data_0212d64c;
    u8 *obj;

    *(s32 *) ((u8 *) arg0 + 0x1cc) = func_02084b48(arg0, &loc);
    *(s32 *) ((u8 *) arg0 + 0x1cc) = func_0211851c(*(s32 *) ((u8 *) arg0 + 0x1cc), 0x17);
    *(s32 *) ((u8 *) arg0 + 0x1d0) = 0x22;
    obj                            = *(u8 **) arg0;
    obj[0x92]                      = obj[0x92] + 1;
}
