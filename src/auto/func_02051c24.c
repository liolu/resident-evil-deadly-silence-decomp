/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
typedef struct {
    u8 pad[0x91];
    u8 kind;
} Obj;

extern void *data_027e000c;
extern Handler data_0211cf50[];

void func_02051c24(void) {
    data_0211cf50[((Obj *) data_027e000c)->kind]();
}
