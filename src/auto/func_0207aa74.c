/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK func_020fef24(void *, s32, s32 *);
extern s32 func_0211851c(s32, s32);

void func_0207aa74(s32 *arg0, s32 arg1, s32 *arg2) {
    s32 buf[3];
    s32 t;

    func_020fef24(arg0, (s32) arg0 + 0xC, buf);
    t       = func_0211851c(arg1 - arg0[0], buf[0] - arg0[0]);
    arg2[0] = arg1;
    arg2[1] = t * (buf[1] - arg0[1]) + arg0[1];
    arg2[2] = t * (buf[2] - arg0[2]) + arg0[2];
}
