/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02075738(M2C_UNK, M2C_UNK);
void func_020914e4(M2C_UNK, M2C_UNK, M2C_UNK);

void func_020403f4(s32 arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, s16 *, 0x94) = -1;
        func_020914e4(arg0 + 0x54, 6, 6);
        M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) - 1);
        if (M2C_FIELD(arg0, s16 *, 0xA8) == 0) {
            M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
        }
    }
    func_02075738(0, 0x400);
}
