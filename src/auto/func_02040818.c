/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*DispFn)(void *);
extern DispFn data_0211cb08[];

void func_02040818(u8 *arg0) {
    data_0211cb08[arg0[0x92]](arg0);
}
