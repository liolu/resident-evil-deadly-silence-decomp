#include "m2c.h"
#include "engine.h"

void func_0207164c(void);

extern M2C_UNK data_0213ad98;

void func_0200fce8(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0xE8) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 3);
    M2C_FIELD(arg0, u8 *, 0xE9) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 0xEA) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 0);
    func_0207164c();
}
