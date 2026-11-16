/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211c624[];
extern void *data_027e000c;

void func_0202e850(void) {
    data_0211c624[M2C_FIELD(data_027e000c, u8 *, 0x93)]();
}
