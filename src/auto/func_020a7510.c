/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void *);

typedef struct {
    Fn f[5];
} Tbl5;

extern Tbl5 data_0212e898;

typedef struct {
    u8 pad[146];
    u8 kind;
} Obj;

void func_020a7510(Obj *arg0) {
    Tbl5 loc;
    u32 idx;

    loc = *(Tbl5 *) &data_0212e898;
    idx = arg0->kind - 18;
    loc.f[idx](arg0);
}
