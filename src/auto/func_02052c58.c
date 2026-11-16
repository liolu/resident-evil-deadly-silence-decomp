/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0212cfc0[];
extern u8 *data_027e000c;

void func_02052c58(void) {
    data_0212cfc0[data_027e000c[0x91]]();
}
