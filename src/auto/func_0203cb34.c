/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211c9f0[];
extern u8 *data_027e000c;

void func_0203cb34(void) {
    data_0211c9f0[data_027e000c[0xA]]();
}
