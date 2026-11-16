/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
typedef struct {
    u8 pad[0x4c];
    u8 *p;
} Holder;

extern Handler data_02124800[];
extern Holder data_0213b890;

void func_020ba180(void) {
    data_02124800[data_0213b890.p[0xf]]();
}
