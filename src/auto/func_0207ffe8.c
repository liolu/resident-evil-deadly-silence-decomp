/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_0207cbb8(s32 *);
u32 func_0207f61c(void);
M2C_UNK func_02082d64(void);
s32 func_02088470(void);

void func_0207ffe8(void **arg0) {
    s32 sp0[4];
    s32 temp_r3;
    s32 temp_r2;
    void *temp_r1;

    func_02082d64();
    if ((func_02088470() == 0) && (func_0207f61c() < 6U)) {
        temp_r1 = *arg0;
        temp_r3 = M2C_FIELD(temp_r1, s32 *, 0x38);
        temp_r2 = M2C_FIELD(temp_r1, s32 *, 0x34);
        sp0[0]  = M2C_FIELD(temp_r1, s32 *, 0x30);
        sp0[1]  = temp_r2;
        sp0[2]  = temp_r3;
        func_0207cbb8(sp0);
    }
    M2C_FIELD(*arg0, s16 *, 0x44) = 0x800;
}
