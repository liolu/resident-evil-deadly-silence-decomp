/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern void func_020884b0(void);
extern void func_02116dac(s32, s32);
extern s32 func_02117094(s32, s32);
extern s32 func_02117de0(void);
extern s32 func_02117e20(u16);
extern s32 func_02117e68(void);
extern s32 func_02117eb0(s32, s32);

u16 func_02088330(u16 arg0) {
    s32 temp_r0;
    s32 temp_r4;
    u16 var_r4;

    var_r4 = arg0;
    func_020884b0();
    temp_r0 = func_02117e68();
    if (func_02117094(0, temp_r0) == 0) {
        temp_r4 = func_02117e20(var_r4);
        func_02116dac(temp_r4, func_02117eb0(0x3D5B6DB7, temp_r0));
        var_r4 = func_02117de0();
    }
    return var_r4;
}
