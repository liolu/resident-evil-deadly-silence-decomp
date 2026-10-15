/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02052188(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_02052e74(void) {
    M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
    func_02052188(-0x32, -0x32, 1);
}
