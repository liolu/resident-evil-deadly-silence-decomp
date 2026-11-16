/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);
typedef struct {
    u32 w[5];
} T20;
extern T20 data_0212f5a0;
extern u8 data_0213b890[];

void func_020bf698(void) {
    T20 loc;

    loc = data_0212f5a0;
    ((Fn *) &loc)[data_0213b890[0x21]]();
}
