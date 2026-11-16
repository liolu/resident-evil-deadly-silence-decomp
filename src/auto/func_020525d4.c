/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0212cff0[];
extern void *data_027e000c;

void func_020525d4(void) {
    data_0212cff0[M2C_FIELD(data_027e000c, u8 *, 0x91)]();
}
