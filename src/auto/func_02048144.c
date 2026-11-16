/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020b8110(u16, s16);                    /* extern */
extern u16 data_0212cba8;
extern void *data_027e000c;

void func_02048144(s32 arg0, s32 arg1) {
    u16 tbl[12][2];
    u16 *src;
    u16 *dst;
    u32 n;
    s32 flag;
    u16 tmp;

    src = &data_0212cba8;
    dst = (u16 *) tbl;
    n   = 0x18;
    do {
        tmp = *src;
        src++;
        n -= 1;
        *dst = tmp;
        dst++;
    } while (n != 0);
    if (M2C_FIELD(data_027e000c, u8 *, 9) == 0x10) {
        flag = 1;
    } else {
        flag = 0;
    }
    func_020b8110(tbl[arg0][flag], (s16) (arg1 * 0x64));
}
