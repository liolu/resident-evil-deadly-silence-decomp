/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020066c8(void *);
u32 func_0200da14(void);
M2C_UNK func_0200dfe4(void);
M2C_UNK func_0200e300(void);
M2C_UNK func_021060e8(s32, s32, s32);
extern s32 data_021372a8;
extern s32 data_021372d8;

void func_0200da20(void *arg0, s32 arg1) {
    volatile s32 sp0;
    s32 temp_r0;

    data_021372d8 = arg1;
    temp_r0       = func_0200da14();
    sp0           = 0;
    func_021060e8(sp0, data_021372d8, temp_r0);
    func_020066c8(arg0);
    func_0200dfe4();
    func_0200e300();
    data_021372a8 = data_021372d8 + 0x20;
}
