/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020b6b5c(void);
void func_020b81e4(u16, s32, s32);
extern u16 data_02121dc0[];
extern u16 data_02121d78[];

void func_020abdb4(s32 arg0, s32 arg1, s32 arg2) {
    u16 *tbl;

    if (func_020b6b5c() != 0) {
        tbl = data_02121dc0;
    } else {
        tbl = data_02121d78;
    }
    func_020b81e4(tbl[arg1 + (arg0 * 4)], arg2, 0);
}
