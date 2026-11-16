/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void *func_020f27b0(void *, void *);

void *func_020f29b8(void *arg0, u32 arg1) {
    void *n;
    void *r;

    n = func_020f27b0(arg0, NULL);
    while (n != NULL) {
        if (*(u32 *) ((u8 *) n + 0x18) <= arg1 && arg1 < *(u32 *) ((u8 *) n + 0x1C)) {
            r = func_020f29b8((u8 *) n + 0xC, arg1);
            if (r == NULL) {
                r = n;
            }
            return r;
        }
        n = func_020f27b0(arg0, n);
    }
    return NULL;
}
