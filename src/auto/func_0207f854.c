/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_01ff8000(s32);
s32 func_01ff8010(s32);

void func_0207f854(void *arg0) {
    s32 temp_r5;
    s32 temp_r0;
    s32 v;

    temp_r5                                             = func_01ff8000(M2C_FIELD(arg0, s32 *, 0x1CC));
    temp_r0                                             = func_01ff8010(M2C_FIELD(arg0, s32 *, 0x1CC));
    v                                                   = (temp_r5 << 9) >> 12;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x34) = v - 0x800;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s16 *, 0x46) = (s16) ((temp_r0 << 7) >> 12);
    M2C_FIELD(arg0, s32 *, 0x1CC)                       = (M2C_FIELD(arg0, s32 *, 0x1CC) + 0x800) & 0xFFFF;
}
