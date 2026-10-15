/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_01ffd504(M2C_UNK);
void func_020559cc(M2C_UNK, M2C_UNK);
M2C_UNK func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);

void func_0201f834(s32 arg0) {
    if ((func_0209109c(0, 0x400, 5) != 0) && (M2C_FIELD(arg0, u8 *, 0xA1) == 9)) {
        M2C_FIELD(arg0, u8 *, 0x92) = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + 1);
        func_020559cc(arg0, 0xA);
        M2C_FIELD(arg0, s8 *, 0xA3)  = 0;
        M2C_FIELD(arg0, s16 *, 0xA6) = 0x82;
    }
    func_01ffd504(0);
}
