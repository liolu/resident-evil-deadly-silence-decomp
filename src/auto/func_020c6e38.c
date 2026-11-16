/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern void func_020c7b78(void);
extern u8 data_0213b890[];

void func_020c6e38(void) {
    u8 *obj;
    u8 cnt;

    obj = *(u8 **) (data_0213b890 + 0x4C);
    if ((obj[0x96] == 0) && (obj[0xB2] == 0)) {
        obj[0xE8] = 1;
        if (data_0213b890[0x23] != 0) {
            cnt                 = data_0213b890[0x22];
            data_0213b890[0x23] = 0;
            data_0213b890[0x22] = cnt + 1;
            return;
        }
        func_020c7b78();
    }
}
