/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef s32 (*Handler)(void *);
extern Handler data_0211d250[];

typedef struct {
    u8 pad[8];
    u8 *ptr;
} Obj;

s32 func_02059588(Obj *arg0) {
    u8 kind;
    s32 res;

    kind = *arg0->ptr;
    if (kind >= 0x80 && kind <= 0x8B) {
        res       = data_0211d250[kind - 0x80](arg0);
        arg0->ptr = arg0->ptr + res;
    }
    return 0;
}
