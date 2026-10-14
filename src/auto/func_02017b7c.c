#include "m2c.h"
#include "engine.h"

s32 func_02017b7c(s32 arg0) {
    void *temp_ip;

    temp_ip = M2C_FIELD(arg0, void **, 0x84);
    if ((temp_ip != NULL) && ((M2C_FIELD(temp_ip, s32 *, 0x1C) + (M2C_FIELD(temp_ip, s32 *, 0x14) + M2C_FIELD(temp_ip, s32 *, 0x18))) != 0)) {
        return (s32) temp_ip;
    }
    return arg0 + 0x64;
}
