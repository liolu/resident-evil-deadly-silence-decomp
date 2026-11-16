/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02076e50(void *);
extern u8 data_021206d8[];
extern u8 *data_02137ed8;

void func_02098030(void) {
    u8 *sp0;
    u8 *base;
    s32 off;
    u32 var_r5;

    var_r5 = 0;
    do {
        base = data_02137ed8;
        off  = var_r5 << 5;
        if (*(s32 *) (base + (var_r5 << 5) + 4) != 0) {
            func_02076e50(base + 4 + off);
            if ((data_021206d8 + data_02137ed8[var_r5 + 0x264] * 4)[3] != 0) {
                sp0 = data_02137ed8 + 0x84 + var_r5 * 0x78;
                func_02076e50(&sp0);
            }
        }
        var_r5 += 1;
    } while (var_r5 < 4);
}
