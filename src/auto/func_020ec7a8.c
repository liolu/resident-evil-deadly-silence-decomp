/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020ec7a8(void *arg0, void *arg1) {
    u8 *src = (u8 *) arg0;
    u8 *dst = (u8 *) arg1;

    *(s8 *) (dst + 0)    = *(s8 *) (src + 0);
    *(s8 *) (dst + 1)    = *(s8 *) (src + 1);
    *(s8 *) (dst + 2)    = *(s8 *) (src + 2);
    *(s8 *) (dst + 3)    = *(s8 *) (src + 3);
    *(s32 *) (dst + 4)   = (s32) (src[7] | ((src[4] << 0x18) | (src[5] << 0x10) | (src[6] << 8)));
    *(s32 *) (dst + 8)   = (s32) (src[0xB] | ((src[8] << 0x18) | (src[9] << 0x10) | (src[0xA] << 8)));
    *(s16 *) (dst + 0xC) = (s16) ((src[0xC] << 8) | src[0xD]);
    *(s8 *) (dst + 0x3C) = *(s8 *) (src + 0xE);
    *(s8 *) (dst + 0x3D) = *(s8 *) (src + 0xF);
}
