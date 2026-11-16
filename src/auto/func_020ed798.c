/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020ed6b0(void);
s32 func_020ecf34(s32);
s32 *func_020ecf04(s32);
void func_020ed6b8(s32);

void func_020ed798(s32 arg0, void *arg1) {
    s32 *temp_r0;

    if (func_020ed6b0() <= 0 && func_020ecf34(arg0 + 0x4E254) != 0) {
        temp_r0                     = func_020ecf04(arg0 + 0x4E254);
        M2C_FIELD(arg1, s32 *, 0)   = (s32) *temp_r0;
        M2C_FIELD(arg1, void **, 4) = (void *) ((u8 *) temp_r0 + 4);
        M2C_FIELD(arg1, s32 **, 8)  = (s32 *) ((u8 *) temp_r0 + 0x204);
        func_020ed6b8(arg0);
        return;
    }
    M2C_FIELD(arg1, s32 *, 0)   = -1;
    M2C_FIELD(arg1, void **, 4) = NULL;
    M2C_FIELD(arg1, s32 **, 8)  = NULL;
}
