/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02073d44(void);
extern u16 data_0211db1c[];
extern u16 data_0213ad30;
extern u16 data_0213ad3c[];
extern u8 data_0213ad48[];

void func_02073b40(void) {
    u16 *p;
    u16 mask;
    u16 var_lr;
    u32 var_ip;
    u16 *o;

    var_lr = 0;
    var_ip = 0;
    p      = (u16 *) ((u8 *) data_0211db1c + (data_0213ad48[8] << 5));
    mask   = data_0213ad30;
    do {
        u16 temp_r0 = *p;
        p += 1;
        if (temp_r0 & mask) {
            var_lr = (u16) (var_lr | (1 << var_ip));
        }
        var_ip += 1;
    } while (var_ip < 0x10U);
    o    = data_0213ad3c;
    o[2] = o[0];
    o[0] = var_lr;
    o[1] = (u16) (var_lr & ~o[2]);
    func_02073d44();
}
