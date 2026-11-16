/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    u8 a;
    u8 pad;
    u8 b;
    u8 c;
    u16 zero;
    u16 d;
    u16 e;
} Blk;

void func_020062ac(u8, Blk *);

void func_0208ea20(s32 arg0, s32 arg1, u8 arg2, u16 arg3, u8 arg4, u8 arg5, u8 arg6) {
    Blk loc;
    u8 v;

    v        = *(u8 *) (arg0 + arg1 + 0x14);
    loc.b    = arg6;
    loc.zero = 0;
    loc.c    = arg5;
    loc.d    = arg3;
    loc.e    = arg4;
    loc.a    = arg2;
    func_020062ac(v, &loc);
}
