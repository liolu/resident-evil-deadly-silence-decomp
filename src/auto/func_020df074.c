/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern void func_020deb88(void *);
extern void func_020dd470(void);
extern void func_020dd47c(void);
extern void func_020e19c4(void);
extern void func_020e1368(void *, s32);
extern void func_020e1a90(void *, s32);
extern void func_020e67e0(s32, s32);
extern void func_020e69c0(s32);
extern u32 data_0212fe08[];

void func_020df074(void *arg0) {
    s32 r4;
    void *obj;
    void (*fp)(void *);

    r4 = *(s32 *) ((u8 *) arg0 + 0x94);
    if (arg0 == NULL) {
        func_020deb88(data_0212fe08);
        return;
    }
    func_020e19c4();
    func_020dd47c();
    *((u8 *) arg0 + 2) = 4;
    func_020e1a90(arg0, *(s32 *) ((u8 *) arg0 + 0x10));
    obj = *(void **) ((u8 *) arg0 + 0x14);
    fp  = (void (*)(void *))(*(void ***) obj)[5];
    fp(obj);
    func_020e67e0(r4, *(s16 *) ((u8 *) arg0 + 0x3E) << 0xB);
    func_020dd470();
    func_020e69c0(r4);
    func_020e1368(arg0, 1);
}
