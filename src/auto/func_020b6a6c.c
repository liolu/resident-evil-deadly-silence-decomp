/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020b82fc(u16 value);
extern u16 *data_0212367c[];
extern u16 *data_0212363c[];
extern u8 data_0213ad48[];
extern u8 data_0213ad98[];
extern u32 data_0213bb18[];

void func_020b6a6c(void) {
    u16 value;

    if (data_0213ad48[4] == 0) {
        value = data_0212367c[data_0213ad98[0]][data_0213ad98[1]];
    } else {
        u32 sel = (data_0213bb18[0x1FC / 4] << 28) >> 30;

        value = data_0212363c[sel][data_0213ad98[1]];
    }
    func_020b82fc(value);
}
