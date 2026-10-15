/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02017b4c(M2C_UNK);

extern M2C_UNK data_02143cc0;

void func_0201625c(s32 arg0) {
    func_02017b4c(arg0);
    M2C_FIELD(arg0, u8 *, 6) = (u8) M2C_FIELD(&data_02143cc0, u8 *, 0xF4C);
}
