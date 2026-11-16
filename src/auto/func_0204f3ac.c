/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*DispFn)(void);
extern DispFn data_0211ce58[];

void func_0204f3ac(u8 *arg0) {
    data_0211ce58[arg0[0x93]]();
}
