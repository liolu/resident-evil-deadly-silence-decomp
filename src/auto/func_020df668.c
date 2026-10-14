/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020dd470(void);
void func_020dd47c(void);
void func_020df410(M2C_UNK);
void func_020df530(M2C_UNK);
void func_020df6dc(M2C_UNK);
void func_020dfddc(M2C_UNK);

void func_020df668(s32 arg0) {
    s8 temp_r0;

    if ((s32) M2C_FIELD(arg0, s32 *, 0xA0) > 0) {
        func_020dd47c();
        func_020df530(arg0);
        func_020dd470();
    }
    temp_r0 = M2C_FIELD(arg0, s8 *, 1);
    if (temp_r0 == 2) {
        func_020df6dc(arg0);
    } else if (temp_r0 == 1) {
        func_020dfddc(arg0);
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0xA4) <= 0) {
        return;
    }
    func_020dd47c();
    func_020df410(arg0);
    func_020dd470();
}
