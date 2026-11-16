/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 func_02004ba4(void *obj);
extern s32 func_02004bc8(void);
extern u8 *data_02136eb0;

s32 func_020040d0(void) {
    s32 found;
    s32 idx;
    u8 *obj;
    u8 *ent;

    found = -1;
    idx   = func_02004bc8();
    goto check;

body:
    obj = data_02136eb0;
    ent = *(u8 **) (obj + 0x30) + idx * 8;
    if ((ent[5] == 0xFF) && (ent[6] == 0)) {
        found  = idx;
        ent[6] = 1;
        goto done;
    }
    idx = func_02004ba4(obj);

check:
    if (idx != -1) {
        goto body;
    }
done:
    return found;
}
