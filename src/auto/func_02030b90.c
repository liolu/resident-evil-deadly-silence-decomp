/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020b3a24(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213db04;
extern void *data_027e000c;

void func_02030b90(void) {
    func_020b3a24((s32) &data_0213db04, (s32) M2C_FIELD(data_027e000c, u8 *, 0xBF));
    M2C_FIELD(data_027e000c, s8 *, 0x92) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
}
