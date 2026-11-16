/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020e45b8(void);
void func_020e4aac(void);
void func_020e5edc(void);
void func_020e4a9c(void);
void func_02103b00(s32);
extern u32 data_02153054[];
extern u32 data_0215301c[];

void func_020e6424(void) {
    volatile s32 sp0;

    if (data_02153054[0] == 1) {
        do {
            if (func_020e45b8() == 0) {
                func_020e4aac();
                if (data_0215301c[4] == 0) {
                    data_0215301c[4] = 1;
                    func_020e5edc();
                }
                func_020e4a9c();
                func_02103b00(0);
            }
            data_02153054[0x7C] += 1;
        } while (data_02153054[0] == 1);
    }
    data_02153054[1] = 1;
}
