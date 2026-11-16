/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211fbec[];
extern void *data_02137898;

void func_0208d8d4(void) {
    data_0211fbec[M2C_FIELD(data_02137898, u8 *, 0x4)]();
}
