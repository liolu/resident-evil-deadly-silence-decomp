/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02083c38(void *);
void func_0208398c(void *);
void func_02083964(void *);
void func_02053bec(void);

void func_02083cd0(void *arg0) {
    switch (M2C_FIELD(arg0, u8 *, 0x4)) {
        case 0:
            func_02083c38(arg0);
            break;
        case 1:
            func_0208398c(arg0);
            break;
        case 2:
        case 3:
            func_02083964(arg0);
            break;
        case 4:
            break;
        default:
            func_02083964(arg0);
            break;
    }
    func_02053bec();
}
