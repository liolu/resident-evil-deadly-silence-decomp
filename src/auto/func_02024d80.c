/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211c3b8[];
extern u8 *data_027e000c;

void func_02024d80(void) {
    data_0211c3b8[data_027e000c[0xA]]();
}
