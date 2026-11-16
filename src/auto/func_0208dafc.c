/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211fbf4[];
extern void *data_0213789c;

void func_0208dafc(void) {
    data_0211fbf4[M2C_FIELD(data_0213789c, u8 *, 0x4)]();
}
