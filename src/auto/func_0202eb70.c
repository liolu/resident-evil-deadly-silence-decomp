/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
typedef struct {
    u8 pad[0xa];
    u8 kind;
} Obj;

extern void *data_027e000c;
extern Handler data_0211c674[];

void func_0202eb70(void) {
    data_0211c674[((Obj *) data_027e000c)->kind & 0xf]();
}
