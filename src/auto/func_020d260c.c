/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_02126520[];
extern u8 data_0213ad84;
extern u8 data_0213b890[];

void func_020d1fc0(void);

void func_020d260c(void) {
    if (data_0213ad84 == 0) {
        func_020d1fc0();
        data_02126520[M2C_FIELD(data_0213b890, u8 *, 0x21)]();
    }
}
