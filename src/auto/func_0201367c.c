/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_021060a4(s32, void *, s32);
extern u8 data_0213ae4c[];
extern u8 data_0213ae60[];

void func_0201367c(void) {
    volatile s32 sp0 = 0;

    data_0213ae4c[1] = 0;
    func_021060a4(sp0, data_0213ae60, 0x30);
    data_0213ae4c[3] = 0x19;
}
