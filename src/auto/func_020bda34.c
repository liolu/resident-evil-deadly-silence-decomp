/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);
extern Fn data_02124a28[];
extern u8 data_0213b890[];

void func_020bda34(void) {
    u8 *p = *(u8 **) (data_0213b890 + 0x4C);
    p[2]  = 1;
    data_02124a28[data_0213b890[0x21]]();
}
