/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Handler)(void *);
extern Handler data_021219d4[];
void func_020a81c4(void *);

typedef struct {
    u8 pad0[0x0A];
    u8 mode;
    u8 pad1[0x92 - 0x0B];
    u8 kind;
} Obj;

void func_020a764c(void *arg0) {
    data_021219d4[((Obj *) arg0)->kind - 0x12](arg0);
    if (((Obj *) arg0)->mode == 6) {
        func_020a81c4(arg0);
    }
}
