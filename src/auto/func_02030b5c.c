/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211c718[];
extern void *data_027e000c;

void func_02030b5c(void) {
    data_0211c718[M2C_FIELD(data_027e000c, u8 *, 0x93)]();
}
