/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0212cfb0[];
extern void *data_027e000c;

void func_02052a4c(void) {
    data_0212cfb0[M2C_FIELD(data_027e000c, u8 *, 0x91)]();
}
