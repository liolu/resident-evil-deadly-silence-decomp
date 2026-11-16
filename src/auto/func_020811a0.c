/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct Sub {
    u8 pad0[8];
    u8 f8;
} Sub;

typedef struct Hdr {
    u8 pad0[10];
    u8 fA;
} Hdr;

typedef struct Obj {
    Hdr *f0;
    u8 pad1[0x44];
    Sub *f48;
    u8 pad2[0x44];
    s32 f90;
} Obj;

void func_02082ee0(void *);
extern u8 data_0212deb0[];

void func_020811a0(Obj *arg0) {
    func_02082ee0(arg0);
    arg0->f48->f8 = 1;
    arg0->f90     = *(s32 *) (data_0212deb0 + arg0->f0->fA * 12);
}
