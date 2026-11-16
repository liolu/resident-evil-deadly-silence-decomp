/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void *);
extern Handler data_0211ce7c[];
s16 func_02075738(u32, u32);

typedef struct {
    u8 pad0[0x92];
    u8 kind;
} Obj;

void func_0204fb44(void *arg0) {
    *(s16 *) ((u8 *) arg0 + 0x182) = func_02075738(1, 0x80);
    data_0211ce7c[((Obj *) arg0)->kind](arg0);
}
