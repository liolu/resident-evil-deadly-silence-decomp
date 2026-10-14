/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0208302c(M2C_UNK);

void func_020811e0(s32 arg0) {
    func_0208302c(arg0);
    M2C_FIELD(arg0, u8 *, 5) = (u8) (M2C_FIELD(arg0, u8 *, 5) | 2);
    M2C_FIELD(arg0, s32 *, 0x1CC) = 0;
}
