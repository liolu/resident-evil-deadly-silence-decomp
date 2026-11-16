/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_0200d374(M2C_UNK);
s32 func_0200d38c();
M2C_UNK func_0200d3b0(M2C_UNK);
M2C_UNK func_020b86d0(s32);
extern u8 data_0213abc4[];

typedef struct {
    u8 pad[0x18];
    u16 h;
} Sub;

void func_020b737c(void) {
    u8 *base;

    base = data_0213abc4;
    if (func_0200d38c() != 0) {
        func_0200d374(0);
    }
    if (*(s32 *) (base + 0x11C) != 0) {
        func_0200d3b0(0);
        func_020b86d0(*(s32 *) (base + 0x11C));
    }
    *(s32 *) (base + 0x11C)     = 0;
    ((Sub *) (base + 0x100))->h = 0;
    base[0x114]                 = 0;
}
