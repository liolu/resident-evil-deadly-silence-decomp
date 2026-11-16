/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_021248f8[];
extern void *data_027e000c;

void func_020bc160(void) {
    data_021248f8[M2C_FIELD(data_027e000c, u8 *, 0x92)]();
}
