/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*DispFn)(void *);
extern DispFn data_0211be10[];

void func_02013efc(u8 *arg0) {
    data_0211be10[arg0[0x19]](arg0);
}
