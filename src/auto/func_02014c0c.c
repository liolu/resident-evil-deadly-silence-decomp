/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02076e50(void);
void func_021060a4(s32, void *, s32);
extern u8 data_0214bcc0[];

void func_02014c0c(void *arg0) {
    volatile s32 sp0;

    func_02076e50();
    sp0 = 0;
    func_021060a4(sp0, arg0, 0x58);
    data_0214bcc0[0x7A2] -= 1;
}
