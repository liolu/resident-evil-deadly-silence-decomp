/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0212f590;
extern M2C_UNK data_0213b890;

typedef struct {
    u32 w[4];
} T16;

void func_020bfeac(void) {
    T16 loc;

    loc = *(T16 *) &data_0212f590;
    ((void (**)(void)) &loc)[M2C_FIELD(&data_0213b890, u8 *, 0x21)]();
}
