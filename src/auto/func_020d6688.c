/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_020059ac(void);
void func_020c46b4(s32);
typedef struct {
    u8 pad0[0x1f];
    u8 st;
    u8 pad1[0x53 - 0x20];
    u8 f53;
} Glob;
extern Glob data_0213b890;

void func_020d6688(void) {
    u8 st;

    st = data_0213b890.st;
    if (st == 2) {
        func_020059ac();
        func_020c46b4(0);
        return;
    }
    if (st == 0) {
        data_0213b890.f53 = 1;
    }
}
