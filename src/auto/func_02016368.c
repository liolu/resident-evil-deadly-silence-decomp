/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0211be98[];
void func_02017bac(void *arg0);

void func_02016368(u8 *arg0) {
    arg0[1] = 1;
    arg0[2] = 2;
    func_02017bac(arg0);
    arg0[3] = data_0211be98[arg0[4]];
}
