/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0208b398(M2C_UNK);
void func_0208b3b0(M2C_UNK);
M2C_UNK func_0208b7c8(M2C_UNK);
M2C_UNK func_0208b904(M2C_UNK);

s32 func_0208b768(s32 arg0) {
    s32 var_r4;

    var_r4 = 0;
    M2C_FIELD(arg0, u8 *, 0x2A5) = (u8) func_0208b904(arg0);
    if (M2C_FIELD(arg0, u8 *, 0x2A5) != 0) {
        func_0208b3b0(arg0);
        var_r4 = 1;
    } else if (func_0208b7c8(arg0) != 0) {
        func_0208b398(arg0);
        var_r4 = 1;
    }
    return var_r4;
}
