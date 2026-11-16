/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_02052188(s32 arg0, s32 arg1, u8 arg2);
extern u8 data_02143cc0[];
extern void *data_027e000c;

s32 func_02052d08(void) {
    M2C_FIELD(data_027e000c, u8 *, 0x91) = M2C_FIELD(data_027e000c, u8 *, 0x91) + 1;
    return func_02052188(0x32, 0, (M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 1) ? 2 : 1);
}
