/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u32 func_02059a30(void);
void func_02059a68(u8 *, u32);
extern u8 data_0213db24;
extern u8 data_0213db26;

void func_020599dc(u32 arg0, u32 arg1) {
    u32 var_r0;
    s32 temp_r2;

    var_r0 = arg0;
    if (var_r0 >= 8) {
        var_r0 = func_02059a30();
    }
    temp_r2 = var_r0 * 0x38;
    if ((&data_0213db26)[temp_r2] == 0 && var_r0 < 8) {
        func_02059a68(&data_0213db24 + temp_r2, arg1);
    }
}
