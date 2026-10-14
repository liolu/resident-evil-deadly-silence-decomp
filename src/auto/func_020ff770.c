#include "m2c.h"

M2C_UNK func_020ff7e4(M2C_UNK *);                   /* extern */
extern M2C_UNK data_021587f2;

void func_020ff770(void) {
    *(s32 *)0x04001000 &= ~0x40000000;
    func_020ff7e4(&data_021587f2);
}
