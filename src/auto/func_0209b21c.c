/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020c4798(M2C_UNK);

extern void *data_02137ed8;
extern M2C_UNK data_0213caa0;

void func_0209b21c(void) {
    M2C_FIELD(data_02137ed8, u8 *, 0x24AF) = (u8) ((M2C_FIELD(data_02137ed8, u8 *, 0x24AF) & ~1) | 1);
    if ((u32) M2C_FIELD(&data_0213caa0, u8 *, 0x705) <= 1U) {
        func_020c4798(4);
    }
    M2C_FIELD(&data_0213caa0, s8 *, 0x300) = 0xA;
}
