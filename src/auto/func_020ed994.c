/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    u8 pad[24];
    s32 slot[4];
} Dst;

typedef struct {
    u8 pad[24];
    s32 val;
} Src;

M2C_UNK func_020ed37c(s32);

s32 func_020ed994(Dst *arg0, Src *arg1) {
    s32 i;
    s32 v;

    for (i = 0; i < 4; i++) {
        if (arg0->slot[i] == 0) {
            v             = arg1->val;
            arg0->slot[i] = v;
            func_020ed37c(v);
            return v;
        }
    }
    return 0;
}
