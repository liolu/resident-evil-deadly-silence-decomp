/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020769b0(M2C_UNK);
void func_02076bb4(M2C_UNK);
void func_021061d8(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0214bcc0;

void func_02017c64(s32 arg0) {
    func_02076bb4(arg0 + 0xAC);
    func_020769b0(arg0 + 0xAD);
    func_021061d8(arg0, 0, 0xBC);
    M2C_FIELD(&data_0214bcc0, s8 *, 0x7A0) = (s8) (M2C_FIELD(&data_0214bcc0, s8 *, 0x7A0) + 1);
}
