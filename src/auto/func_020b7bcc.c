#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213ac70;

s32 func_020b7bcc(s32 arg0) {
    return *((M2C_UNK *)((s8 *)&data_0213ac70 + (arg0 * 0xC)));
}
