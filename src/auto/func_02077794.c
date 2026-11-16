/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*DispFn)(void *);
extern DispFn data_0211e70c[];

void func_02077794(u8 *arg0) {
    data_0211e70c[arg0[2]](arg0);
}
