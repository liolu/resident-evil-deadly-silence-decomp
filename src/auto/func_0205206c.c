/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211cf28[];
extern u8 *data_027e000c;

void func_0205206c(void) {
    data_0211cf28[data_027e000c[0x90]]();
    *(s32 *) (data_027e000c + 0x18) = 0;
    *(u16 *) (data_027e000c + 0x42) = 0;
    *(u16 *) (data_027e000c + 0x46) = 0;
}
