/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void);
extern Handler data_0211c20c[];
extern void *data_027e000c;

void func_0201e4e0(void) {
    u8 *st = *(u8 **) &data_027e000c;
    data_0211c20c[st[0x92]]();
}
