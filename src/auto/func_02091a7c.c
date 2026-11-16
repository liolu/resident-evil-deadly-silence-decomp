/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02091ab8(s32, u8 *);

u16 func_02091a7c(s32 arg0) {
    u8 buf[4];
    u32 t;

    func_02091ab8(arg0, buf);
    t = ((buf[3] << 10) | (buf[2] << 5)) | buf[1];
    return (u16) t;
}
