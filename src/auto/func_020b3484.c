/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_0213ad48[];
extern u8 data_0213bde0[];
void func_020b3a24(void);
u8 func_02095204(u8);

void func_020b3484(void *arg0, s32 arg1) {
    func_020b3a24();
    if (data_0213ad48[4] != 0) {
        if (arg0 == data_0213bde0) {
            if ((arg1 & 0x80) != 0) {
                func_02095204((u8) arg1);
            }
        }
    }
}
