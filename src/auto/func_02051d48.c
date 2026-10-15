/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020512c0(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_02051d48(void) {
    M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
    func_020512c0(-0x28, 0x28, 1);
}
