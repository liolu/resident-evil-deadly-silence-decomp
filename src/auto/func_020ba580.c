/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_02124808[];
extern u8 data_0213b890;

void func_020ba580(void) {
    u8 *p = *(u8 **) ((u8 *) &data_0213b890 + 0x4c);
    data_02124808[p[15]]();
}
