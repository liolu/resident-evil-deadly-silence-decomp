/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020dcd10(void *);
void func_020dce68(void *);
void func_020dcfac(void *);

void func_020dcc64(void *arg0) {
    s16 temp_r1;

    temp_r1 = *(s16 *) ((u8 *) arg0 + 0x9C);
    if (temp_r1 == 2) {
        func_020dcd10(arg0);
    } else if (temp_r1 == 1) {
        func_020dce68(arg0);
    } else if (temp_r1 == 0) {
        func_020dcfac(arg0);
    }
}
