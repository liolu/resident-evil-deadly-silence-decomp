/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020782c0(void);
s32 func_021029a0(s32 arg0, void (*arg1)(void));
s32 func_020ff30c(s32 arg0);
s32 func_02102810(s32 arg0);

void func_0207833c(void) {
    u16 tmp;

    func_021029a0(1, func_020782c0);
    func_020ff30c(1);
    func_02102810(1);
    tmp                          = *(volatile u16 *) 0x04000208;
    *(volatile u16 *) 0x04000208 = 1;
}
