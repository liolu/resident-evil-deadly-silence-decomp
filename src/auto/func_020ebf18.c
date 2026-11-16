/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020ebf5c(void *);
void func_020ec1b4(void *);

void func_020ebf18(void *arg0) {
    s8 k;

    k = *(s8 *) ((u8 *) arg0 + 9);
    if (k == 2) {
        func_020ebf5c(arg0);
    } else if (k == 1) {
        func_020ec1b4(arg0);
    }
}
