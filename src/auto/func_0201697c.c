/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0201697c(s32 arg0) {
    M2C_FIELD(arg0, void **, 0x90) = (void *) M2C_FIELD(arg0, void **, 0x8C);
    M2C_FIELD(arg0, void **, 0x90) = (void *) (M2C_FIELD(arg0, void **, 0x90) + (M2C_FIELD(arg0, u8 *, 4) * 4));
    M2C_FIELD(arg0, u8 *, 0x1E) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x90), u8 *, 1);
    M2C_FIELD(arg0, s32 *, 0x98) = (s32) (M2C_FIELD(arg0, s32 *, 0x94) + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x90), u8 *, 0) * 4));
}
