/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020a1c08();
extern void (*data_021368d0)(s32);
extern void (*data_021368d8)(s32);
extern u8 data_02143cc0[];

void func_020a1bac(void) {
    s32 v;

    v = *(s32 *) (data_02143cc0 + 0xF34);
    if (v != 0) {
        data_021368d0(v);
    }
    v = *(s32 *) (data_02143cc0 + 0xF38);
    if (v != 0) {
        data_021368d8(v);
    }
    func_020a1c08();
}
