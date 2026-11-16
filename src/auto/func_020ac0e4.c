/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef s32 (*Fn)(void);
extern Fn data_02121cd4[];
extern Fn data_02121ca0[];
extern u8 data_0213ad48[];
extern u8 data_0213ad98;
extern u8 data_0213bb18[];
extern u8 *data_027e000c;
s32 func_020b818c(s32, s32, s32);

void func_020ac0e4(void) {
    s32 r;

    if (data_0213ad48[4] == 0) {
        r = data_02121cd4[data_0213ad98]();
    } else {
        r = data_02121ca0[((*(u32 *) (data_0213bb18 + 0x1FC)) << 28) >> 30]();
    }
    func_020b818c(r, (s32) (data_027e000c + 0x30), 0);
}
