/* compiler: 1.2/sp2p3 */
#include "m2c.h"

char *func_021124b8(char *arg0, s32 arg1) {
    u8 c  = arg1;
    u8 *p = (u8 *) arg0;
    u8 ch;

    ch = *p++;
    while (ch != 0) {
        if (ch == c) {
            return (char *) (p - 1);
        }
        ch = *p++;
    }
    if (c != 0) {
        return NULL;
    }
    return (char *) (p - 1);
}
