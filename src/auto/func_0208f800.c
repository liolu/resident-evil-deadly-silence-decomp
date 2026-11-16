/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211ff88[];
extern void *data_02137894;

void func_0208f800(void) {
    data_0211ff88[M2C_FIELD(data_02137894, u8 *, 0x4)]();
}
