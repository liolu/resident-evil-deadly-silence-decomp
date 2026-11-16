/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */
M2C_UNK func_0201eb90(void *);                      /* extern */

void func_0201eb38(void *arg0, M2C_UNK arg1, s16 arg2) {
    s32 temp_r8;
    s32 temp_r7;
    s16 temp_r6;
    s16 temp_r5;
    s16 temp_r4;

    temp_r8                      = M2C_FIELD(arg0, s32 *, 0x30);
    temp_r7                      = M2C_FIELD(arg0, s32 *, 0x38);
    temp_r6                      = M2C_FIELD(arg0, s16 *, 0x3C);
    temp_r5                      = M2C_FIELD(arg0, s16 *, 0x40);
    temp_r4                      = M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0xA6) = (s16) (temp_r4 * arg2);
    func_01ffd504(arg1);
    func_0201eb90(arg0);
    M2C_FIELD(arg0, s32 *, 0x30) = temp_r8;
    M2C_FIELD(arg0, s32 *, 0x38) = temp_r7;
    M2C_FIELD(arg0, s16 *, 0x3C) = temp_r6;
    M2C_FIELD(arg0, s16 *, 0x40) = temp_r5;
    M2C_FIELD(arg0, s16 *, 0xA6) = temp_r4;
}
