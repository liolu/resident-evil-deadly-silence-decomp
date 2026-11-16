/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*DispFn)(void *);
extern DispFn data_0211cb64[];

void func_02042744(u8 *arg0) {
    data_0211cb64[arg0[0x92]](arg0);
}
