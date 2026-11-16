/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0212cf98[];
extern u8 *data_027e000c;

void func_02052cd4(void) {
    data_0212cf98[data_027e000c[0x91]]();
}
