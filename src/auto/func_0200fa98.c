/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_021061d8(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_027e01ec;
extern M2C_UNK data_027e0238;

void func_0200fa98(void) {
    func_021061d8((s32) &data_027e01ec, 0, 0x40);
    func_021061d8((s32) &data_027e0238, 0, 0xC);
    *(s32 *) 0x04001000 &= ~0xE000;
}
