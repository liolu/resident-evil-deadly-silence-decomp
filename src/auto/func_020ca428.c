/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);
typedef struct {
    u32 a;
    u32 b;
    u32 c;
} T3;
extern T3 data_0212f660;
extern u8 data_0213b890[];

void func_020ca428(void) {
    T3 loc = data_0212f660;
    ((Fn *) &loc)[data_0213b890[0x20]]();
}
