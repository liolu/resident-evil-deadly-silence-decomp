/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void);
extern Handler data_0212cfb8[];
extern void *data_027e000c;

void func_02052d50(void) {
    u8 *st = *(u8 **) &data_027e000c;
    data_0212cfb8[st[0x91]]();
}
