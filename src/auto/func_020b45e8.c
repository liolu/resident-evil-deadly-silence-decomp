/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s32 ptr;
    u8 pad[0x54];
    s32 pend;
} Glob;

extern Glob data_0213daa8;
extern u8 data_0213ad98[];
extern void func_02017f68(s32 a, u8 b, s32 c, s32 d, s32 e);
s32 func_020b45e8(void) {
    s32 p;
    s32 pend;

    p                 = data_0213daa8.ptr;
    data_0213daa8.ptr = p + 2;
    pend              = data_0213daa8.pend;
    if (pend != 0) {
        func_02017f68(9, data_0213ad98[0xb], 0, 0, pend);
        data_0213daa8.pend = 0;
    }
    return 1;
}
