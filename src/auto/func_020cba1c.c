/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern s32 func_020c0148(s32);
extern void func_020c4798(s32);
extern void func_020cb75c(void);
extern s32 func_020cb94c(void);
extern u8 data_0213ad84;
extern u8 data_0213ad98[];
extern u32 data_0213b890[];

void func_020cba1c(void) {
    u8 *g;

    if (data_0213ad84 != 0) {
        return;
    }
    if ((data_0213ad98[5] & 0x80) != 0) {
        return;
    }
    g = (u8 *) data_0213b890;
    if (func_020c0148((s32) (*(u8 **) (g + 0x4C) + 0x48)) == 1) {
        func_020c4798(2);
        return;
    }
    func_020cb75c();
    if (func_020cb94c() == 1) {
        u8 n;

        n                                      = ((u8 *) data_0213b890)[0x21];
        *(s16 *) ((u8 *) data_0213b890 + 0x26) = 0x1E;
        ((u8 *) data_0213b890)[0x21]           = n + 1;
    }
}
