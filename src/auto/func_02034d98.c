/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*DispFn)(void);
extern DispFn data_0211c824[];

void func_02034d98(u8 *arg0) {
    data_0211c824[arg0[0x92]]();
}
