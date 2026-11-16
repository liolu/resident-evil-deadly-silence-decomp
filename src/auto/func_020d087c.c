/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_021262e4[];
extern u8 data_0213b890[];
void func_020d0300(u8 *);

void func_020d087c(void) {
    u8 i;

    data_021262e4[data_0213b890[0x20]]();
    i = 0;
    do {
        func_020d0300(*(u8 **) (data_0213b890 + 0x4C) + 4 + i * 0x1C);
        i = (u8) (i + 1);
    } while (i < 3);
}
