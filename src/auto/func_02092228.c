/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020931d8(void *, u16);
extern u8 data_0213ad98[];
extern u8 data_0213e394[];
extern u8 data_0213e3c0[];

void func_02092228(void) {
    u8 flag;
    u16 r1;
    u16 r4;

    flag                = data_0213ad98[5] & 1;
    r1                  = (u16) (data_0213e394[6] + 0xAC);
    data_0213e394[0x16] = flag;
    r4                  = r1;
    if (data_0213e394[0x16] != 0) {
        r1 = 0x120;
    } else {
        r4 = 0x120;
    }
    *(u16 *) (data_0213e394 + 0x3A) = *(u16 *) (data_0213e394 + 0x1E);
    func_020931d8(data_0213e3c0, r1);
    *(u16 *) (data_0213e394 + 0x3A) = *(u16 *) (data_0213e394 + 0x20);
    func_020931d8(data_0213e3c0, r4);
}
