/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_021061d8(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_027e01ac;
extern M2C_UNK data_027e022c;

void func_0200fae8(void) {
    func_021061d8((s32) &data_027e01ac, 0, 0x40);
    func_021061d8((s32) &data_027e022c, 0, 0xC);
    *(s32 *) 0x04000000 &= ~0xE000;
}
