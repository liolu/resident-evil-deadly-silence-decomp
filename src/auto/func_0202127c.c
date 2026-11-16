/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void *);
extern Handler data_0211c2ec[];
void func_0201ec54(void *arg0, s32 arg1, s32 arg2);

void func_0202127c(void *arg0) {
    data_0211c2ec[((u8 *) arg0)[0x92]](arg0);
    func_0201ec54(arg0, 12, 0);
}
