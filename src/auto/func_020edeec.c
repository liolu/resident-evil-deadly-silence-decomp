#include "m2c.h"
void func_020edeec(u8 *arg0) {
    u8 *p = arg0 + 0x204;
    s32 i = 0;
    if (*(s32 *) (arg0 + 0xC210) <= 0) {
        return;
    }
    do {
        *p = (u8) i;
        p++;
        i++;
    } while (i < *(s32 *) (arg0 + 0xC210));
}
