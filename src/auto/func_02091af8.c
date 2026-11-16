/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b6b5c(void);
s32 func_020b6d94(u8, s32);
void func_020b6e8c(u8);
extern u8 data_0211f2ac[];

s32 func_02091af8(void *arg0) {
    s32 r0;
    u32 i;
    s32 kind;

    if (func_020b6b5c() != 0) {
        kind = 0xC2;
    } else {
        kind = 0xBD;
    }
    func_020b6e8c(kind);
    i = 0;
    do {
        r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xD4), u16 *, 0xA) & (1 << i);
        if (r0 != 0) {
            r0 = func_020b6d94(data_0211f2ac[i * 3], 0);
        }
        i++;
    } while (i < 8);
    return r0;
}
