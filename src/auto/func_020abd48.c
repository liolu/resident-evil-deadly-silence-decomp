/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020b6b5c(void);
void func_020b81e4(u16, s32, s32);
extern u8 data_02121cf0[];

void func_020abd48(s32 arg0, s32 arg1) {
    func_020b81e4(((u16 *) (data_02121cf0 + arg0 * 4))[func_020b6b5c()], arg1, 0);
}
