/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

int func_0208af50(int, int, VecFx32 *, VecFx32 *);
void func_020feef0(s32, s32, s32);
void func_020fec68(void *, void *);
void func_0207aa74(void *, s32, s32);

void func_0207aae0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    VecFx32 sp0;
    VecFx32 spC;

    func_0208af50(arg0, arg1, &sp0, &spC);
    func_020feef0((s32) &spC, (s32) &sp0, (s32) &spC);
    func_020fec68(&spC, &spC);
    func_0207aa74(&sp0, arg2, arg3);
}
