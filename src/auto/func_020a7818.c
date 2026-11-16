/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void *);
extern Handler data_0213af30[];
extern u32 data_0213bdcc[];
extern u16 data_0213daa8[];
void func_020ad960(void);

void func_020a7818(void *arg0) {
    u8 *obj = (u8 *) arg0;

    if (obj[0x93] == 0) {
        if ((data_0213bdcc[0x44 / 4] & 0x40) || (obj[0xC0] & 0x80)) {
            data_0213daa8[0x74 / 2] = (u16) (data_0213daa8[0x74 / 2] | 0x40);
        }
        obj[0xC0] = (u8) (obj[0xC0] & ~0x80);
        func_020ad960();
    }
    data_0213af30[obj[0x91]](arg0);
}
