/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0208c0b8(s32 arg0) {
    s16 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s16 *, 0x29C);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x29C) = (s16) (temp_r0 - 1);
    if (M2C_FIELD(arg0, s16 *, 0x29C) == 0) {
        M2C_FIELD(arg0, s16 *, 0x28C) = (s16) M2C_FIELD(arg0, s16 *, 0x290);
        M2C_FIELD(arg0, s16 *, 0x28E) = (s16) M2C_FIELD(arg0, s16 *, 0x292);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x28C) = (s16) (M2C_FIELD(arg0, s16 *, 0x28C) + M2C_FIELD(arg0, s16 *, 0x294));
    M2C_FIELD(arg0, s16 *, 0x28E) = (s16) (M2C_FIELD(arg0, s16 *, 0x28E) + M2C_FIELD(arg0, s16 *, 0x296));
    M2C_FIELD(arg0, s16 *, 0x294) = (s16) (M2C_FIELD(arg0, s16 *, 0x294) + M2C_FIELD(arg0, s16 *, 0x298));
    M2C_FIELD(arg0, s16 *, 0x296) = (s16) (M2C_FIELD(arg0, s16 *, 0x296) + M2C_FIELD(arg0, s16 *, 0x29A));
    M2C_FIELD(arg0, s16 *, 0x28C) = (s16) (M2C_FIELD(arg0, s16 *, 0x28C) & 0xFFF);
    M2C_FIELD(arg0, s16 *, 0x28E) = (s16) (M2C_FIELD(arg0, s16 *, 0x28E) & 0xFFF);
}
