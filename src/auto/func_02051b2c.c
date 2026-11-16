/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211cf40[];
extern u8 *data_027e000c;

void func_02051b2c(void) {
    data_0211cf40[data_027e000c[0x91]]();
}
