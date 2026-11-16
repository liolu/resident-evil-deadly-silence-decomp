/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0212cfa8[];
extern u8 *data_027e000c;

void func_02053178(void) {
    data_0212cfa8[data_027e000c[0x90]]();
    *(s32 *) (data_027e000c + 0x18) = 0;
}
