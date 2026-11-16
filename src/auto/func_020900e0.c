/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_0208fed8(void *, void *, void *);         /* extern */
void func_02091310(void *, u8, void *, s32);        /* extern */
void func_02091448(void *, u8, void *, s32);        /* extern */

void func_020900e0(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    u32 sp0[5];
    u32 sp20[3];
    u32 sp32[5];
    u32 sp52[4];

    func_02091448(arg0, arg2, sp0, 1);
    func_02091310(arg0, arg2, sp32, arg3);
    func_0208fed8(arg1, sp20, sp52);
}
