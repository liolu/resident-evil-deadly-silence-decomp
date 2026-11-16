/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02110474(void *, s32, void *);
extern s32 data_02153254;
extern void (*data_02153258)(s32, void *);
extern M2C_UNK data_0215325c;

void func_020e6dc0(s32 arg0, ...) {
    void *args;

    args = (void *) ((u32 *) ((u32) &arg0 & ~0x3) + 1);
    func_02110474(&data_0215325c, arg0, args);
    if (data_02153258 == NULL) {
        return;
    }
    data_02153258(data_02153254, &data_0215325c);
}
