/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211c9dc[];
extern void *data_027e000c;

void func_0203db14(void) {
    data_0211c9dc[M2C_FIELD(data_027e000c, u8 *, 0x91)]();
}
