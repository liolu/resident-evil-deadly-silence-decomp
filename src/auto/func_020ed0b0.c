/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 func_020ecf54(void *);
extern void func_020ed458(void *, u32 *, u32 *);
extern u32 *func_020ecf1c(void *);
extern void func_02110374(void *, u32, u32);
extern void func_020ecee4(void *);

void func_020ed0b0(u8 *arg0) {
    u32 sp0;
    u32 sp4;
    u32 *r4;

    if (func_020ecf54(arg0 + 0x4E254) != 0) {
        return;
    }
    func_020ed458(arg0, &sp0, &sp4);
    if (sp0 == 0) {
        return;
    }
    r4 = func_020ecf1c(arg0 + 0x4E254);
    func_02110374(r4, sp0, 0xC208);
    *r4 = sp4;
    func_020ecee4(arg0 + 0x4E254);
}
