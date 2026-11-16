/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u32 func_02059b28(s32);
extern void *data_0211d558[];
extern s32 data_027e000c;

s16 func_02059b70(s32 arg0) {
    s16 var_r0;
    u32 temp_r0;
    u8 *var_r2;

    temp_r0 = func_02059b28(data_027e000c);
    if (temp_r0 >= 2U) {
        return -1;
    }
    var_r2 = data_0211d558[temp_r0];
    goto check;
loop:
    if (*(u16 *) (var_r2 + 2) == arg0) {
        return var_r0;
    }
    var_r2 += 4;
check:
    var_r0 = *(s16 *) var_r2;
    if (var_r0 >= 0) {
        goto loop;
    }
    return -1;
}
