#include "m2c.h"

M2C_UNK func_020ff7e4(M2C_UNK *);                   /* extern */
extern M2C_UNK data_021587ea;

void func_020ff7c0(void) {
    *(s32 *) 0x04000000 &= ~0x40000000;
    func_020ff7e4(&data_021587ea);
}
