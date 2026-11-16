/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s8 a;
    u8 pad;
    u8 b;
    u8 c;
    s16 d;
    s16 e;
    s16 f;
} Loc;

void func_020062ac(s32, void *);

void func_0209f910(s32 arg0, s8 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5) {
    Loc loc;

    loc.a = arg1;
    loc.b = arg5;
    loc.d = 0;
    loc.c = arg4;
    loc.e = arg2;
    loc.f = arg3;
    func_020062ac(arg0, &loc);
}
