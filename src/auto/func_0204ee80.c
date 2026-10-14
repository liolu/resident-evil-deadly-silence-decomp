/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0204e9c8(void);
void func_0204ecfc(void);
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_0204ee80(void) {
    u8 temp_r0;

    M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) | 0xE0);
    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA);
    if (temp_r0 != 0x80) {
        if (temp_r0 == 0) {
            func_0204ecfc();
        } else {
            func_0204e9c8();
        }
    }
    func_02075738(0, 0x100);
}
