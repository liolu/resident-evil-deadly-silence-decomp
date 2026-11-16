/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*DispFn)(void *);
extern DispFn data_0211cb7c[];

void func_02041364(u8 *arg0) {
    data_0211cb7c[arg0[0x93]](arg0);
}
