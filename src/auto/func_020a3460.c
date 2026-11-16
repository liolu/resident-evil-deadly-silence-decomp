/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    s16 key;
    u8 a;
    u8 b;
} Entry37;

extern M2C_UNK func_020f8678(s32, s32, s32);
extern Entry37 data_02121388[];

void func_020a3460(s32 arg0, void *arg1, u8 *arg2) {
    Entry37 *e = data_02121388;

    func_020f8678(*(s32 *) ((u8 *) arg1 + 0xC), 1, 0x1F0000);
    goto check;
body:
    if (e->key == arg0) {
        arg2[0x53] = e->b;
        arg2[0x52] = e->a;
        goto done;
    }
    e++;
check:
    if (e->key != -1) {
        goto body;
    }
    arg2[0x53] = 0;
    arg2[0x52] = 0x1F;
done:
    return;
}
