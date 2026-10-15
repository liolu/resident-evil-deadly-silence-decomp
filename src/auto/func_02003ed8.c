#include "engine.h"
#include "m2c.h"

void func_02003d2c(void);

void func_02003ed8(s32 arg0) {
    M2C_FIELD(arg0, volatile s32 *, 8)    = 0x1555;
    M2C_FIELD(arg0, volatile s32 *, 0xC)  = 0x1000;
    M2C_FIELD(arg0, volatile s32 *, 0xC)  = 0x800;
    M2C_FIELD(arg0, volatile s32 *, 0x10) = 0x01000000;
    func_02003d2c();
}
